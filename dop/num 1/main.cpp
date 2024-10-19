#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    short Q1,P1,Q2,P2,A;
    int cost=INT_MAX;
    cin>>Q1>>P1>>Q2>>P2>>A;
    
    
    for(int i=0;i<=A/Q1+1;i++ )
    {
        for(int j=0;j<=A/Q2+1;j++)
        {
            if((Q1*i+Q2*j)>=A)
            {
                cost=min(cost,P1*i+P2*j);
                break;
            }
        }

    }
    cout<<cost;

}
