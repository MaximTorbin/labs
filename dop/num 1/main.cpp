#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    short Q1,P1,Q2,P2,A;
    int cost;
    cin>>Q1>>P1>>Q2>>P2>>A;
    if ( ((Q1*1.0f)/P1)>=((Q2*1.0f)/P2))
        cost=min(ceil((A*1.0f)/Q1)*P1,float((ceil((A*1.0f)/Q1)-1)*P1+ceil(((A-(A/Q1)*Q1)*1.0f)/Q2)*P2  ));
    else
        cost=min(ceil((A*1.0f)/Q2)*P2,float((ceil((A*1.0f)/Q2)-1)*P2+ceil(((A-(A/Q2)*Q2)*1.0f)/Q1)*P1  ));
    cout<<cost;

}