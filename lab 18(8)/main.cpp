#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920,1080}), "Lab 18(8)");
    window.setFramerateLimit(60);

    sf::CircleShape triangle(240.f,3);
    triangle.setFillColor(sf::Color::Blue);
    triangle.setOrigin(triangle.getGeometricCenter());
    triangle.setPosition(sf::Vector2f(400, 400));
    triangle.setRotation(sf::degrees(60.f));


    sf::CircleShape Circle(150.f);
    Circle.setFillColor(sf::Color::Green);
    Circle.setPosition(sf::Vector2f(1000, 700));


    sf::RectangleShape Rectangle({300.f, 90.f});
    Rectangle.setFillColor(sf::Color::Red);
    Rectangle.setOrigin(triangle.getGeometricCenter());
    Rectangle.setPosition(sf::Vector2f(800, 400));
    Rectangle.setRotation(sf::degrees(90.f));

    while (window.isOpen())
    {
        triangle.rotate(sf::degrees(1.f));
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }


        window.clear(sf::Color::White);
        window.draw(triangle);
        window.draw(Circle);
        window.draw(Rectangle);
        window.display();
    }
}