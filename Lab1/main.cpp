/* 1)���������� -  ��� ����������� ������� ������, � ������� ����� �������� ������ �� ���������.

2) 
�������������: int, short, long, long long
������������� ��� �����: unsigned int, unsigned short, unsigned long, unsigned long long
������������: float, double, long double
����������: char, unsigned char
���������� - bool

3) ��������:               ������:                          min   /   max:
     int                     4�                  -2 147 483 648   /   2 147 483 647
     unsigned int            4�                               0   /   4 294 967 295
     short                   2�                         -32 768   /   32 767
     unsigned short          2�                               0   /   65 535
     long                    4�                  -2 147 483 648   /   2 147 483 647
     unsigned long           4�                               0   /   4 294 967 295
     long long               8�            -9223372036854775807   /   9223372036854775807
     unsigned long long      8�                               0   /   18446744073709551615
     float                   4�                -2 147 483 648.0   /   2 147 483 647.0
     double                  8�   -9 223 372 036 854 775 808 .0   /   9 223 372 036 854 775 807.0
     long double             8�   -9 223 372 036 854 775 808 .0   /   9 223 372 036 854 775 807.0
     char                    1�                            -128   /   127
     unsigned char           1�                               0   /   255
     bool                    1�                               0   /   1
*/
#include <iostream>
#include <limits>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    cout << "���: int, ������:" << sizeof(int) << "�, min: " << numeric_limits<int>::min() << ", max: " <<
        numeric_limits<int>::max() << endl;
    int a_int=-200, b_int=1000;
    cout << "������: " << a_int << "+" << b_int << "=" << a_int + b_int << endl;
    cout << "���: unsigned int, ������:" << sizeof(unsigned int) << "�, min: " << numeric_limits<unsigned int>::min() << ", max: " <<
        numeric_limits<unsigned int>::max() << endl;
    unsigned int a_uint = 250, b_uint = 1750;
    cout << "������: " << a_uint << "+" << b_uint << "=" << a_uint + b_uint << endl;
    cout << "���: short, ������:" << sizeof(short) << "�, min: " << numeric_limits<short>::min() << ", max: " <<
        numeric_limits<short>::max() << endl;
    short a_s = 5000, b_s= 2400;
    cout << "������: " << a_s << "+" << b_s << "=" << a_s + b_s << endl;
    cout << "���: unsigned short, ������:" << sizeof(unsigned short) << "�, min: " << numeric_limits<unsigned short>::min() << ", max: " <<
        numeric_limits<unsigned short>::max() << endl;
    unsigned short a_us = 30, b_us = 724;
    cout << "������: " << a_us << "+" << b_us << "=" << a_us + b_us << endl;
    cout << "���: long, ������:" << sizeof(long) << "�, min: " << numeric_limits<long>::min() << ", max: " <<
        numeric_limits<long>::max() << endl;
    long a_l = 140, b_l = 420;
    cout << "������: " << a_l << "+" << b_l << "=" << a_l + b_l << endl;
    cout << "���: unsigned long, ������:" << sizeof(unsigned long) << "�, min: " << numeric_limits<unsigned long>::min() << ", max: " <<
        numeric_limits<unsigned long>::max() << endl;
    unsigned long a_ul = 600, b_ul = 245;
    cout << "������: " << a_ul << "+" << b_ul << "=" << a_ul + b_ul << endl;
    cout << "���: long long, ������:" << sizeof(long long) << "�, min: " << numeric_limits<long long>::min() << ", max: " <<
        numeric_limits<long long>::max() << endl;
    long long a_ll = 430, b_ll = 6071;
    cout << "������: " << a_ll << "+" << b_ll << "=" << a_ll + b_ll << endl;
    cout << "���: unsigned long long, ������:" << sizeof(unsigned long long) << "�, min: " << numeric_limits<unsigned long long>::min() << ", max: " <<
        numeric_limits<unsigned long long>::max() << endl;
    unsigned long long a_ull = 800, b_ull = 1300;
    cout << "������: " << a_ull << "+" << b_ull << "=" << a_ull + b_ull << endl;
    cout << "���: float, ������:" << sizeof(float) << "�, min: " << numeric_limits<float>::min() << ", max: " <<
        numeric_limits<float>::max() << endl;
    float a_f = 30.5f, b_f = 69.49f;
    cout << "������: " << a_f << "+" << b_f << "=" << a_f + b_f << endl;
    cout << "���: double, ������:" << sizeof(double) << "�, min: " << numeric_limits<double>::min() << ", max: " <<
        numeric_limits<double>::max() << endl; 
    double a_d = -20.407f, b_d = 568.907f;
    cout << "������: " << a_d << "+" << b_d << "=" << a_d + b_d << endl;
    cout << "���: long double, ������:" << sizeof(long double) << "�, min: " << numeric_limits<long double>::min() << ", max: " <<
        numeric_limits<long double>::max() << endl;
    long double a_ld = 5.999f, b_ld = 0.001f;
    cout << "������: " << a_ld << "+" << b_ld << "=" << a_ld + b_ld << endl;
    cout << "���: char, ������:" << sizeof(char) << "�, min: " << (int)numeric_limits<char>::min() << ", max: " <<
        (int)numeric_limits<char>::max() << endl;
    char a_c = 1, b_c = 2;
    cout << "������: " << int(a_c) << "+" << int(b_c) << "=" << a_c + b_c << endl;
    cout << "���: unsigned char, ������:" << sizeof(unsigned char) << "�, min: " << (int)numeric_limits<unsigned char>::min() << ", max: " <<
        (int)numeric_limits<unsigned char>::max() << endl;
    unsigned char a_uc = 1, b_uc = 25;
    cout << "������: " << int(a_uc) << "+" <<int(b_uc) << "=" << a_uc + b_uc << endl;
    cout << "���: bool, ������:" << sizeof(bool) << "�" << endl;
    return 0;
}