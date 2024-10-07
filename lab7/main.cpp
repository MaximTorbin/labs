#include <iostream>
#include "string"
#include "functions.h"
#include <algorithm>

using namespace std;
int main()
{
    int matrix[100][100];
    int n;
    n=func::readingmatrix(matrix);
    func::sortmatrix(matrix,n);
    func::writematrix(matrix,n);

}
    