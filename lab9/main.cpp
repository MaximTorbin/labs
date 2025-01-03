#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    unsigned int number=305419896;
    unsigned char *pa=reinterpret_cast<unsigned char*>(&number);
    for(int i=sizeof(unsigned int)-1;i>=0;i--)
    {
        cout<<bitset<8>(pa[i])<<" ";
    }
}