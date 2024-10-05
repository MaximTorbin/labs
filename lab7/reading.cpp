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
                // ������� ��������� ������� �������
                int spacePos = str.find(' ', pos);
                
                // ���� ������ �� ������, ����� ������� ������
                if (spacePos == string::npos) {
                    spacePos = str.length();
                }

                // ��������� ��������� � ������������ � ����� �����
                matrix[i][index] = stoi(str.substr(pos, spacePos - pos));
                
                // ��������� ������� � ������
                pos = spacePos + 1; // ���������� ������
                index++;
            }
            i++;
        }
    }
    fin.close();
    return matrix;
}