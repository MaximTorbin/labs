#include <iostream>
#include <algorithm>
using namespace std;

#define TAIL 5
// bool simp(int x)
// {
//     for(int i=2;i<=sqrt(x);i++){
//         if (x % i == 0) {
//             return true;
//         }
//     }
//     return false;
// }
// //№1
// int main(){
//    setlocale(LC_ALL, "RU");
//    cout<<"Введите длинну массива:\n";
//    int l;
//    bool fl=0;
//    cin>>l;
//    int* ar=new int[l];
//    for(int i=0;i<l;i++){
//        cout<<"Введите "<<i+1<<" число: ";
//        cin>>ar[i];
//        if (simp(ar[i]) == 0) {
//            fl = 1;
//        }
//    }
//    if (fl==0) {
//         for(int i=0;i<l-1;i++)
//         {
//          for(int j=i+1;j<l;j++)
//          {
//              if (ar[i]>ar[j])
//                 swap(ar[i],ar[j]);
//         }
//         }
//        cout << "Отсортированные элементы массива:" << endl;
//        for (int i = 0; i < l; i++) {
//            cout << ar[i] << " ";
//        }
//    }
//    else cout << "В массиве есть простой элемент";
//    delete [] ar;
   
// }

// //№2
// int sumD(int a){
// 	int sum=0;
//     while(a)
//     {
//         sum+=a%10;
//         a/=10;
//     }
// 	return sum;
// }

// int mulD(int a)
// {
//     int mul=1;
//     while(a)
//     {
//         mul*=a%10;
//         a/=10;
//     }
//     return mul;
// }

 
// bool sor(int n1,int n2)
// {

//     if (sumD(n1)!=sumD(n2)) return sumD(n1)>sumD(n2);
//     if (mulD(n1)!=mulD(n2)) return mulD(n1)>mulD(n2);
//     return n1>n2;

//     /*if (sumD(n1)>sumD(n2))
//     return true;
//     if (sumD(n1)<sumD(n2))
//     return false;

//     if (mulD(n1)>mulD(n2))
//     return true;
//     if (mulD(n1)<mulD(n2))
//     return false;
    
//     if (n1>n2)
//     return true;
//     return false;*/
// }
// int main()
// {
//     setlocale(LC_ALL, "RU");
//     int a,b,n;
// 	cout<<"Введите длинну последовательности:\n";
//     cin>>n;
//     int *arr=new int[n];
//     for(int i=0;i<n;i++)
//     {
// 		cout<<"Введите"<<i+1<< " элемент";
//         cin>>arr[i];
//     }
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if (sor(arr[i],arr[j]))
//                 swap(arr[i],arr[j]);
//         }
//     }
// 	cout<< "Отсортированный массив:\n";
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

// //№3
// int main() {
//     setlocale(LC_ALL, "Russian");
//     int m, n, pr, prm=INT_MIN, str=-1,a;
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
//         }
//         if (pr > prm) {
//                 prm = pr;
//                 str = i;
//             }
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

//     return 0;
// }


//№4


bool simp(int x)
{
    for(int i=2;i<(sqrt(x)+1);i++){
        if (x % i == 0) {
            return true;
        }
    }
    return false;
}
#include <cmath>
int main()
{
    int n;
    cin>>n;
    int *ar=new int[2*n + TAIL];
    for(int k=0;k<n;k++)
    {
        cin>>ar[k];
    }
    for(int i=0;i<n;i++){
        if (!simp(ar[i]))
        {
            for(int k=i;k<n-1;k++)
            {
                ar[k]=ar[k+1];
            }
            n--;
            i--;
        }
        else
        {
            if (cbrt(ar[i])==int(cbrt(ar[i])))
            {
                n++;
                for(int k=n;k>i;k--)
                {
                    ar[k]=ar[k-1];
                }
                i++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
        // bool fl=1;
        // for(int k=0;k<i;k++)
        // {
        //     if (ar[i]=ar[k])
        //     {
        //         fl=0;
        //         break;
        //     }
        // }
        // if (fl)
        // cout<<ar[i]<<" ";
    }
    
    delete [] ar;
}
