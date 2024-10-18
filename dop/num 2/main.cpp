//билет счастливый, если сумма первых трёх цифр равна сумме последних трёх цифр
#include <iostream>
using namespace std;
short SumOfDigit(short a)
{
    short s=0;
    while(a)
    {
        s+=a%10;
        a/=10;
    }
    return s;
}
int main()
{
    short sumCount[28];
    unsigned short ans=0;
    for(char i=0;i<28;++i)
    {
        sumCount[i]=0;
    }
    for(short num=0;num<1000;++num)
    {
        sumCount[SumOfDigit(num)]+=1;
    }
    for(char i=0;i<28;++i)
    {
        ans+=sumCount[i]*sumCount[i];
    }
    cout<<ans<<endl;
}