#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    unsigned int a=305419896;
    unsigned char *pa=reinterpret_cast<unsigned char*>(&a);
    for(int i=0;i<sizeof(unsigned int);i++)
    {
        cout<<bitset<8>(pa[i])<<endl;
        //bitset<8> byteBits(pa[i]);
        //cout<<"Байт "<<i<<": "<<byteBits<<endl;
    }
}