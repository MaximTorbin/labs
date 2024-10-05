#include "writing.h"
#include <iostream>
#include <fstream> 
using namespace std;
void writematrix()
{
    ofstream fout;
    fout.open("matrix.txt");
    if (!fout.is_open())
    {
        cout<<"ERROR";
    }
    else
    {
        unsigned short n;
        int a;
        cout<<"Введите порядок матрицы:";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            if(i)
            fout<<endl;
            for(int j=0;j<n;j++)
            {
                cout<<"Введите элемент "<<i+1<<" строки "
                <<j+1<<" столбца: ";
                cin>>a;
                fout<<a<<" ";
            }
        }

    }
    fout.close();
}