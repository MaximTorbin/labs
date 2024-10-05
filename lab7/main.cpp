#include <iostream>
#include "string"
#include "functions.h"

using namespace std;
int main()
{
    int Max_n = 100;
    //int **matrix=new int* [Max_n];
    int matrix[100][100];
    /*for (int i = 0; i < Max_n; i++)
    {
        matrix[i] = new int[Max_n];
    }*/
    func::readingmatrix(matrix);
    for (int i = 0; i < 2; i++)
    {
        cout << matrix[i][0];
    }
}
//     ifstream fin;
//     fin.open("matrix.txt");
//     if(!fin.is_open())
//     {
//         cout<<"ERROR";
//     }
//     else
//     {
//         string str;
//         int Max_n=100;
//         int **matrix=new int* [Max_n];
//         for (int i = 0; i < Max_n; i++)
//         {
//             matrix[i] = new int[Max_n];
//         }
//         int i=0;
//         while(!fin.eof())
//         {

//            int pos = 0,index = 0;
//            getline(fin,str);
//            while (pos < str.length())
//            {
//                 // Находим следующую позицию пробела
//                 int spacePos = str.find(' ', pos);

//                 // Если пробел не найден, берем остаток строки
//                 if (spacePos == string::npos) {
//                     spacePos = str.length();
//                 }

//                 // Извлекаем подстроку и конвертируем в целое число
//                 matrix[i][index] = stoi(str.substr(pos, spacePos - pos));

//                 // Обновляем позицию и индекс
//                 pos = spacePos + 1; // Пропускаем пробел
//                 index++;
//             }
//             i++;
//         }
//         int n=i;
//         for(int i=0;i<n;i++)
//         {
//             if(i)
//             cout<<endl;
//             for(int j=0;j<n;j++)
//             cout<<matrix[i][j]<<" ";
//         }
//     }
//     fin.close();
// }
