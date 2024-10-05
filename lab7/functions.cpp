#include "functions.h"
#include <iostream>
using namespace std;

namespace func {
    int readingmatrix(int matrix[100][100])
    {
        setlocale(LC_ALL, "RU");
        int n;
        cout << "Размер матрицы:";
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


    void writematrix(int matrix[100][100], int n)
    {
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
