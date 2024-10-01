#include <iostream>
#include <algorithm>
using namespace std;
bool simp(int x){
    for(int i=2;i<(sqrt(x)+1);i++){
        if (x % i == 0) {
            return true;
        }
    }
    if (x <= 0) {
        return true;
    }
}
//
//int main(){
//    setlocale(LC_ALL, "Russian");
//    cout<<"Введите длинну массива:\n";
//    int l;
//    bool fl=0;
//    cin>>l;
//    int* ar=new int[l];
//    for(int i=0;i<l;i++){
//        cin>>ar[i];
//        if (simp(ar[i]) == 0) {
//            fl = 1;
//        }
//    }
//    if (fl==0) {
//        sort(ar, ar + l);
//        cout << "Отсортированные элементы массива:" << endl;
//        for (int i = 0; i < l; i++) {
//            cout << ar[i] << " ";
//        }
//    }
//    else cout << "В массиве есть простой элемент";
//    return 0;
//    
//}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//struct NumberProperties {
//    int number;
//    int digitSum;
//    int digitProduct;
//
//    NumberProperties(int num) : number(num), digitSum(0), digitProduct(1) {
//        int temp = num;
//        while (temp > 0) {
//            int digit = temp % 10;
//            digitSum += digit;
//            digitProduct *= digit;
//            temp /= 10;
//        }
//    }
//};
//
//// Компаратор для сортировки
//bool compare(const NumberProperties& a, const NumberProperties& b) {
//    if (a.digitSum != b.digitSum) {
//        return a.digitSum < b.digitSum;
//    }
//    if (a.digitProduct != b.digitProduct) {
//        return a.digitProduct < b.digitProduct;
//    }
//    return a.number < b.number;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    int n;
//
//    std::cout << "Введите количество натуральных чисел (n <= 1000): ";
//    std::cin >> n;
//
//    if (n <= 0 || n > 1000) {
//        std::cout << "Ошибка: n должно быть в пределах от 1 до 1000." << std::endl;
//        return 1;
//    }
//
//    std::vector<NumberProperties> numbers;
//
//    // Ввод чисел
//    std::cout << "Введите " << n << " натуральных чисел:" << std::endl;
//    for (int i = 0; i < n; ++i) {
//        int num;
//        std::cin >> num;
//
//        // Проверка на натуральность
//        if (num <= 0) {
//            std::cout << "Ошибка: число должно быть натуральным." << std::endl;
//            return 1;
//        }
//
//        numbers.emplace_back(num); // Создаем объект и добавляем в вектор
//    }
//
//    // Сортировка чисел
//    std::sort(numbers.begin(), numbers.end(), compare);
//
//    // Вывод отсортированных чисел
//    std::cout << "Отсортированные числа:" << std::endl;
//    for (const auto& numProp : numbers) {
//        std::cout << numProp.number << std::endl;
//    }
//
//    return 0; // Успешное завершение программы
//}
int main() {
    setlocale(LC_ALL, "Russian");

    int m, n, pr, prm=0, str=0,a;
    cout << "Количество строк:";
    cin >> m;
    cout << "Количество столбцов:";
    cin >>n;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        pr = 1;
        for (int j=0; j < n; j++) {
            cout << "Введите элемент " << i+1 << " строки " << j+1 << " столбца:";
            cin >> matrix[i][j];
            pr = pr * matrix[i][j];
            if (pr > prm) {
                prm = pr;
                str = i;
            }
        }
    }
    for (int i = 0; i < n;i++) {
        matrix[str][i] = prm;
    }

    cout << "Максимальное произведение:" << prm << endl;
    cout << "Матрица:";

    for (int i = 0; i < m; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j]<<" ";

        }
    }

    return 0;
}
