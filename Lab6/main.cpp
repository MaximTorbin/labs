#include <iostream>
#include <algorithm>
using namespace std;
// bool simp(int x)
// {
//     for(int i=2;i<(sqrt(x)+1);i++){
//         if (x % i == 0) {
//             return true;
//         }
//     }
//     if (x <= 0) {
//         return true;
//     }
// }
// //№1
// int main(){
//    setlocale(LC_ALL, "Russian");
//    cout<<"Введите длинну массива:\n";
//    int l;
//    bool fl=0;
//    cin>>l;
//    int* ar=new int[l];
//    for(int i=0;i<l;i++){
//        cin>>ar[i];
//        if (simp(ar[i]) == 0) {
//            fl = 1;
//            break;
//        }
//    delete [] ar;
//    }
//    if (fl==0) {
//        sort(ar, ar + l);
//        cout << "Отсортированные элементы массива:" << endl;
//        for (int i = 0; i < l; i++) {
//            cout << ar[i] << " ";
//        }
//    }
//    else cout << "В массиве есть простой элемент";
//    return 0;
   
// }

//№2
int sumD(int a){
	int sum=0;
    while(a)
    {
        sum+=a%10;
        a/=10;
    }
	return sum;
}

int mulD(int a)
{
    int mul=1;
    while(a)
    {
        mul*=a%10;
        a/=10;
    }
    return mul;
}

 
bool sor(int n1,int n2)
{
    if (sumD(n1)>sumD(n2))
    return true;
    if (sumD(n1)<sumD(n2))
    return false;

    if (mulD(n1)>mulD(n2))
    return true;
    if (mulD(n1)<mulD(n2))
    return false;
    
    if (n1>n2)
    return true;
    return false;
}
int main()
{
    setlocale(LC_ALL, "RU");
    int a,b,n;
	cout<<"Введите длинну последовательности:\n";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
		cout<<"Введите"<<i+1<< " элемент";
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (sor(arr[i],arr[j]))
            swap(arr[i],arr[j]);
        }
    }
	cout<< "Отсортированный массив:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    delete [] arr;
}

//№3
// int main() {
//     setlocale(LC_ALL, "Russian");
//     int m, n, pr, prm=INT_MIN, str=0,a;
//     cout << "Количество строк:";
//     cin >> m;
//     cout << "Количество столбцов:";
//     cin >>n;
//     int** matrix = new int* [m];
//     for (int i = 0; i < m; i++) {
//         matrix[i] = new int[n];
//     }
//     for (int i = 0; i < m; i++) {
//         pr = 1;
//         for (int j=0; j < n; j++) {
//             cout << "Введите элемент " << i+1 << " строки " << j+1 << " столбца:";
//             cin >> matrix[i][j];
//             pr = pr * matrix[i][j];
//             if (pr > prm) {
//                 prm = pr;
//                 str = i;
//             }
//         }
//     }
//     for (int i = 0; i < n;i++) {
//         matrix[str][i] = prm;
//     }

//     cout << "Максимальное произведение:" << prm << endl;
//     cout << "Матрица:";

//     for (int i = 0; i < m; i++) {
//         cout << endl;
//         for (int j = 0; j < n; j++) {
//             cout << matrix[i][j]<<" ";

//         }
//     }

//     delete [] matrix;
// }
