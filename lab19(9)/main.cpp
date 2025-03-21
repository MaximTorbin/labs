#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <optional>
#include <random>
#include <chrono>
#include <algorithm>

// Функция для проверки, находится ли точка внутри многоугольника
bool isPointInsidePolygon(const std::vector<sf::Vector2f>& polygon, const sf::Vector2f& point) {
    int intersections = 0;
    size_t n = polygon.size();

    for (size_t i = 0; i < n; ++i)
    {
        const sf::Vector2f& p1 = polygon[i];
        const sf::Vector2f& p2 = polygon[(i + 1) % n];

        if ((p1.y > point.y) != (p2.y > point.y))
        {
            float xIntersect = (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
            if (point.x <= xIntersect)
                intersections++;
        }
    }

    return (intersections % 2) == 1;
}


// Функция для получения нормалей ребер многоугольника
std::vector<sf::Vector2f> getNormals(const std::vector<sf::Vector2f>& points)
{
    std::vector<sf::Vector2f> normals;
    size_t n = points.size();
    for (size_t i = 0; i < n; ++i)
    {
        const sf::Vector2f& p1 = points[i];
        const sf::Vector2f& p2 = points[(i + 1) % n];
        sf::Vector2f edge = p2 - p1;
        sf::Vector2f normal(-edge.y, edge.x); // Перпендикулярный вектор
        float length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
        if (length > 0)
            normal /= length; // Нормализуем вектор
        normals.push_back(normal);
    }

    return normals;
}

// Функция для проекции многоугольника на ось
void projectPolygon(const std::vector<sf::Vector2f>& points, const sf::Vector2f& axis, float& min, float& max) {
    min = std::numeric_limits<float>::max();
    max = std::numeric_limits<float>::lowest();

    for (const auto& point : points)
    {
        float projection = point.x * axis.x + point.y * axis.y; // Скалярное произведение
        if (projection < min) min = projection;
        if (projection > max) max = projection;
    }
}

// Функция для проверки пересечения двух выпуклых многоугольников
bool checkCollision(const sf::ConvexShape& shape1, const sf::ConvexShape& shape2) {
    // Получаем точки многоугольников
    std::vector<sf::Vector2f> points1;
    std::vector<sf::Vector2f> points2;

    for (size_t i = 0; i < shape1.getPointCount(); ++i)
        points1.push_back(shape1.getTransform().transformPoint(shape1.getPoint(i)));

    for (size_t i = 0; i < shape2.getPointCount(); ++i)
        points2.push_back(shape2.getTransform().transformPoint(shape2.getPoint(i)));

    // Получаем нормали для обоих многоугольников
    std::vector<sf::Vector2f> normals1 = getNormals(points1);
    std::vector<sf::Vector2f> normals2 = getNormals(points2);

    // Проверяем все оси
    for (const auto& normal : normals1)
    {
        float min1, max1, min2, max2;
        projectPolygon(points1, normal, min1, max1);
        projectPolygon(points2, normal, min2, max2);

        if (max1 < min2 || max2 < min1)
            return false; // Нет пересечения
    }

    for (const auto& normal : normals2)
    {
        float min1, max1, min2, max2;
        projectPolygon(points1, normal, min1, max1);
        projectPolygon(points2, normal, min2, max2);

        if (max1 < min2 || max2 < min1)
            return false; // Нет пересечения
    }

    return true; // Есть пересечение
}


// Генерация случайного многоугольника
sf::ConvexShape generateRandomPolygon(std::mt19937& rng, const sf::Vector2f& position, const sf::Color& color)
{
    std::uniform_int_distribution<int> vertexCountDist(3, 8); // От 3 до 8 вершин
    std::uniform_real_distribution<float> radiusDist(30.0f, 80.0f); // Радиус фигуры
    std::uniform_real_distribution<float> angleDist(0.0f, 2 * 3.14159f); // Угол для вершин

    int vertexCount = vertexCountDist(rng);
    float radius = radiusDist(rng);

    sf::ConvexShape shape;
    shape.setPointCount(vertexCount);

    for (int i = 0; i < vertexCount; ++i)
    {
        float angle = angleDist(rng);
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        shape.setPoint(i, {x, y});
    }

    shape.setPosition(position);
    shape.setOrigin(shape.getGeometricCenter());
    shape.setFillColor(color);

    return shape;
}

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920, 1080}), "Avoid the Shapes");
    window.setFramerateLimit(120);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        return -1; // Ошибка загрузки шрифта
    }
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<float> speedDist(200.0f, 400.0f); // Скорость движения
    std::uniform_real_distribution<float> rotationSpeedDist(-180.0f, 180.0f); // Скорость вращения
    std::uniform_real_distribution<float> spawnDistX(80.0f, 1840.0f); // Позиция спавнаX
    std::uniform_real_distribution<float> spawnDistY(80.0f, 1000.0f); // Позиция спавнаY
    std::uniform_int_distribution<int> colorDist(1, 255); // Для генерации случайного цвета
    std::vector<sf::ConvexShape> shapes;
    std::vector<sf::Vector2f> velocities;
    std::vector<float> rotationSpeeds;

    float timeSinceLastSpawn = 0.0f;
    float spawnInterval = 2.0f; // Интервал спавна фигур
    float gameTime = 0.0f; // Время игры
    int destroyedShapes = 0; // Количество уничтоженных фигур
    bool gameOver = false;
    float totalGameTime = 0.0f; // Общее время игры

    sf::Text statsText(font);
    statsText.setCharacterSize(24);
    statsText.setFillColor(sf::Color::White);
    statsText.setPosition(sf::Vector2f(10.f, 10.f));


    float speed=1;

    // Основной цикл приложения
    while (window.isOpen())
    {
        float deltaTime = 1.0f / 120.0f; // Время между кадрами

        while (const auto event = window.pollEvent())
        {
            if (event.has_value() && event->is<sf::Event::Closed>())
                window.close();
        }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);
        if (!gameOver) {
            // Генерация новых фигур
            timeSinceLastSpawn += deltaTime;
            if (timeSinceLastSpawn >= spawnInterval) {
                timeSinceLastSpawn = 0.0f;

                sf::Color randomColor(colorDist(rng), colorDist(rng), colorDist(rng));

                // Генерация позиции спавна с учетом минимального расстояния от курсора
                sf::Vector2f position;

                do
                {
                    position = {spawnDistX(rng), spawnDistY(rng)};
                } 
                while (std::hypot(position.x - worldMousePos.x, position.y - worldMousePos.y) < 200.0f);


                shapes.push_back(generateRandomPolygon(rng, position, randomColor));
                velocities.push_back(sf::Vector2f(speedDist(rng)*speed, speedDist(rng)*speed));
                rotationSpeeds.push_back(rotationSpeedDist(rng));
            }
            // Движение и вращение фигур
            sf::Vector2f target(mousePos.x, mousePos.y);
            float minDistance = 10.0f;

            for (size_t i = 0; i < shapes.size(); ++i)
            {
                sf::Vector2f direction = target - shapes[i].getPosition();
                
                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                if (length > minDistance)
                {
                    direction /= length;

                    float deltaX = direction.x * velocities[i].x * deltaTime;
                    float deltaY = direction.y * velocities[i].y * deltaTime;

                    // Ограничиваем смещение, чтобы фигура не "перескакивала" курсор
                    if (std::abs(deltaX) > length) deltaX = direction.x * length;
                    if (std::abs(deltaY) > length) deltaY = direction.y * length;

                    // Перемещаем фигуру
                    shapes[i].move(sf::Vector2f(deltaX, deltaY));
                    
                }
                else
                    shapes[i].setPosition(target);
                shapes[i].rotate(sf::degrees(rotationSpeeds[i] * deltaTime));
            }


            // Проверка столкновений фигур
            for (size_t i = 0; i < shapes.size(); ++i)
            {
                for (size_t j = i + 1; j < shapes.size(); ++j)
                {
                    if (checkCollision(shapes[i], shapes[j]))
                    {
                        shapes.erase(shapes.begin() + j);
                        velocities.erase(velocities.begin() + j);
                        rotationSpeeds.erase(rotationSpeeds.begin() + j);
                        shapes.erase(shapes.begin() + i);
                        velocities.erase(velocities.begin() + i);
                        rotationSpeeds.erase(rotationSpeeds.begin() + i);
                        destroyedShapes += 2; 
                        break;
                    }
                }
            }

            // Проверка проигрыша
            for (const auto& shape : shapes) 
            {
                // Получаем точки фигуры в локальных координатах
                std::vector<sf::Vector2f> polygonPoints;
                for (size_t i = 0; i < shape.getPointCount(); ++i)
                {
                    polygonPoints.push_back(shape.getTransform().transformPoint(shape.getPoint(i)));
                }

                // Преобразуем позицию курсора в локальные координаты фигуры
                sf::Vector2f localMousePos = shape.getTransform().getInverse().transformPoint(worldMousePos);

                // Проверяем, находится ли курсор внутри фигуры
                if (isPointInsidePolygon(polygonPoints, worldMousePos))
                {
                    gameOver = true;
                    break;
                }
            }

            // Увеличение сложности
            gameTime += deltaTime;
            totalGameTime += deltaTime;
            if (gameTime > 5.0f)
            {
                spawnInterval *= 0.9f;
                speed*=1.2f;
                gameTime = 0.0f;
            }
        }
        statsText.setString("Time: " + std::to_string(static_cast<int>(totalGameTime)) + "s\nDestroyed: " + std::to_string(destroyedShapes));
        window.clear();
        for (const auto& shape : shapes) 
            window.draw(shape);
        window.draw(statsText);
        if (gameOver)
        {
            sf::Text gameOverText(font);
            gameOverText.setString("Game over!\nTime: " + std::to_string(static_cast<int>
            (totalGameTime)) + "s\nDestroyed: " + std::to_string(destroyedShapes));
            gameOverText.setCharacterSize(24);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(sf::Vector2f(900.f, 540.f));
            window.draw(gameOverText);
        }
        window.display();
    }
}