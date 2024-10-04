#include <iostream>
#include <fstream> 
#include "string"
using namespace std; 
int main()
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
    ifstream fin;
    fin.open("matrix.txt");
    if(!fin.is_open())
    {
        cout<<"ERROR";
    }
    else
    {
        string str;
        while(!fin.eof())
        {
           getline(fin,str);
           cout<<str<<endl;


        }
    }
    fin.close();
}