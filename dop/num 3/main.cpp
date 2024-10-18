#include <iostream>
#include <string>
using namespace std;
bool IsHaveSameDigits(int a)
{
    int *ar=new int(to_string(a).length());
    int i=0;
    while(a)
    {
        ar[i]=a%10;
        a/=10;
        for(int j=0;j<i;j++)
        {
            if (ar[i]==ar[j])
                return true;
        }
        i++;
    }
    return false;

}
bool IsFirstTwo(int a)
{
    while(a>=10)
    {
        a/=10;
    }
    return a==2;
}
int main()
{
    int n;
    cin>>n;
    int *ar=new int[2*n + 50];
    for(int k=0;k<n;k++)
    {
        cin>>ar[k];
    }
    for(int i=0;i<n;i++){
        if (IsFirstTwo(ar[i]))
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
            if (!IsHaveSameDigits(ar[i]))
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
        cout<<ar[i]<<" ";
}