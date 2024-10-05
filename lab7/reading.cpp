#include "reading.h"
arr readingmatrix()
{
    ifstream fin;
    fin.open("matrix.txt");
    if(!fin.is_open())
    {
        cout<<"ERROR";
    }
    else
    {
        string str;
        int Max_n=100;
        int **matrix=new int* [Max_n];
        for (int i = 0; i < Max_n; i++)
        {
            matrix[i] = new int[Max_n];
        }
        int i=0;
        while(!fin.eof())
        {

           int pos = 0,index = 0;
           getline(fin,str);
           while (pos < str.length())
           {
                // Находим следующую позицию пробела
                int spacePos = str.find(' ', pos);
                
                // Если пробел не найден, берем остаток строки
                if (spacePos == string::npos) {
                    spacePos = str.length();
                }

                // Извлекаем подстроку и конвертируем в целое число
                matrix[i][index] = stoi(str.substr(pos, spacePos - pos));
                
                // Обновляем позицию и индекс
                pos = spacePos + 1; // Пропускаем пробел
                index++;
            }
            i++;
        }
    }
    fin.close();
    return matrix;
}