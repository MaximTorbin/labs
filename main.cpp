#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
   /* setlocale(LC_ALL, "RU");
    cout << "Введитe радиус круга:\n";
   float r;
    cin >> r;
    cout <<acos(-1)*pow(r,2);
    return 0;*/
     int x, i;
    cout << "Введите число и бит:";
    cin >>x>> i;
   /*a = 15;
    mask = ~(1 << 3);
    cout << (a&mask);*/
    i = int(pow(2, i));
    cout <<( x |i);

    return 0;
}