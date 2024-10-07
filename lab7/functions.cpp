#include "functions.h"
#include <iostream>
using namespace std;

namespace func {
    bool HaveZero(int a)
    {
        while(a)
        {
            if (a%10==0)
            {
                return 1;
            }
            a/=10;
        }
        return 0;
    }


    int FindMax(int* arr,int size)
    {
        int MaxValue=INT_MIN;
        for(int i=0;i<size;i++)
        {
            if(MaxValue<arr[i])
            MaxValue=arr[i];
        }


        return MaxValue;
    }


    int readingmatrix(int matrix[100][100])
    {
        int n;
        cout << "Порядок матрицы:";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        return n;
    }


    void sortmatrix(int matrix[100][100], int n)
    {
        bool fl=1;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][i]!=FindMax(matrix[i],n))
            {
                fl=0;
                break;
            }
        }
        if (fl)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (HaveZero(matrix[i][j]))
                    matrix[i][j]=matrix[i][i];
                }
            }
        }
    }

    void writematrix(int matrix[100][100], int n)
    {
        cout<<"Матрица:"<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << endl;
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
}
