/* 1)Переменная -  это именованная область памяти, к которой можно получить доступ из программы.

2) 
Целочисленные: int, short, long, long long
Целочисленные без знака: unsigned int, unsigned short, unsigned long, unsigned long long
Вещественные: float, double, long double
Символьные: char, unsigned char
Логический - bool

3) Название:               Размер:                          min   /   max:
     int                     4Б                  -2 147 483 648   /   2 147 483 647
     unsigned int            4Б                               0   /   4 294 967 295
     short                   2Б                         -32 768   /   32 767
     unsigned short          2Б                               0   /   65 535
     long                    4Б                  -2 147 483 648   /   2 147 483 647
     unsigned long           4Б                               0   /   4 294 967 295
     long long               8Б            -9223372036854775807   /   9223372036854775807
     unsigned long long      8Б                               0   /   18446744073709551615
     float                   4Б                -2 147 483 648.0   /   2 147 483 647.0
     double                  8Б   -9 223 372 036 854 775 808 .0   /   9 223 372 036 854 775 807.0
     long double             8Б   -9 223 372 036 854 775 808 .0   /   9 223 372 036 854 775 807.0
     char                    1Б                            -128   /   127
     unsigned char           1Б                               0   /   255
     bool                    1Б                               0   /   1
*/
#include <iostream>
#include <limits>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    cout << "Тип: int, Размер:" << sizeof(int) << "Б, min: " << numeric_limits<int>::min() << ", max: " <<
        numeric_limits<int>::max() << endl;
    int a_int=-200, b_int=1000;
    cout << "Пример: " << a_int << "+" << b_int << "=" << a_int + b_int << endl;
    cout << "Тип: unsigned int, Размер:" << sizeof(unsigned int) << "Б, min: " << numeric_limits<unsigned int>::min() << ", max: " <<
        numeric_limits<unsigned int>::max() << endl;
    unsigned int a_uint = 250, b_uint = 1750;
    cout << "Пример: " << a_uint << "+" << b_uint << "=" << a_uint + b_uint << endl;
    cout << "Тип: short, Размер:" << sizeof(short) << "Б, min: " << numeric_limits<short>::min() << ", max: " <<
        numeric_limits<short>::max() << endl;
    short a_s = 5000, b_s= 2400;
    cout << "Пример: " << a_s << "+" << b_s << "=" << a_s + b_s << endl;
    cout << "Тип: unsigned short, Размер:" << sizeof(unsigned short) << "Б, min: " << numeric_limits<unsigned short>::min() << ", max: " <<
        numeric_limits<unsigned short>::max() << endl;
    unsigned short a_us = 30, b_us = 724;
    cout << "Пример: " << a_us << "+" << b_us << "=" << a_us + b_us << endl;
    cout << "Тип: long, Размер:" << sizeof(long) << "Б, min: " << numeric_limits<long>::min() << ", max: " <<
        numeric_limits<long>::max() << endl;
    long a_l = 140, b_l = 420;
    cout << "Пример: " << a_l << "+" << b_l << "=" << a_l + b_l << endl;
    cout << "Тип: unsigned long, Размер:" << sizeof(unsigned long) << "Б, min: " << numeric_limits<unsigned long>::min() << ", max: " <<
        numeric_limits<unsigned long>::max() << endl;
    unsigned long a_ul = 600, b_ul = 245;
    cout << "Пример: " << a_ul << "+" << b_ul << "=" << a_ul + b_ul << endl;
    cout << "Тип: long long, Размер:" << sizeof(long long) << "Б, min: " << numeric_limits<long long>::min() << ", max: " <<
        numeric_limits<long long>::max() << endl;
    long long a_ll = 430, b_ll = 6071;
    cout << "Пример: " << a_ll << "+" << b_ll << "=" << a_ll + b_ll << endl;
    cout << "Тип: unsigned long long, Размер:" << sizeof(unsigned long long) << "Б, min: " << numeric_limits<unsigned long long>::min() << ", max: " <<
        numeric_limits<unsigned long long>::max() << endl;
    unsigned long long a_ull = 800, b_ull = 1300;
    cout << "Пример: " << a_ull << "+" << b_ull << "=" << a_ull + b_ull << endl;
    cout << "Тип: float, Размер:" << sizeof(float) << "Б, min: " << numeric_limits<float>::min() << ", max: " <<
        numeric_limits<float>::max() << endl;
    float a_f = 30.5f, b_f = 69.49f;
    cout << "Пример: " << a_f << "+" << b_f << "=" << a_f + b_f << endl;
    cout << "Тип: double, Размер:" << sizeof(double) << "Б, min: " << numeric_limits<double>::min() << ", max: " <<
        numeric_limits<double>::max() << endl; 
    double a_d = -20.407f, b_d = 568.907f;
    cout << "Пример: " << a_d << "+" << b_d << "=" << a_d + b_d << endl;
    cout << "Тип: long double, Размер:" << sizeof(long double) << "Б, min: " << numeric_limits<long double>::min() << ", max: " <<
        numeric_limits<long double>::max() << endl;
    long double a_ld = 5.999f, b_ld = 0.001f;
    cout << "Пример: " << a_ld << "+" << b_ld << "=" << a_ld + b_ld << endl;
    cout << "Тип: char, Размер:" << sizeof(char) << "Б, min: " << (int)numeric_limits<char>::min() << ", max: " <<
        (int)numeric_limits<char>::max() << endl;
    char a_c = 1, b_c = 2;
    cout << "Пример: " << int(a_c) << "+" << int(b_c) << "=" << a_c + b_c << endl;
    cout << "Тип: unsigned char, Размер:" << sizeof(unsigned char) << "Б, min: " << (int)numeric_limits<unsigned char>::min() << ", max: " <<
        (int)numeric_limits<unsigned char>::max() << endl;
    unsigned char a_uc = 1, b_uc = 25;
    cout << "Пример: " << int(a_uc) << "+" <<int(b_uc) << "=" << a_uc + b_uc << endl;
    cout << "Тип: bool, Размер:" << sizeof(bool) << "Б" << endl;
    return 0;
}