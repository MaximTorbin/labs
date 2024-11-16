#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main()
{
    int x1,x2,y1,y2,r1,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    double r1_squared = r1 * r1;
    double r2_squared = r2 * r2;
    double area1 = r1_squared*acos(-1);
    double area2 = r2_squared*acos(-1);
    if(d>r1+r2)
    {
        printf("%.3f\n",area1+area2);
    }
    else if(d <=abs(r1 - r2)) 
    {
         printf("%.3f\n",max(area1,area2));
    }
    else
    {
        double part1 = r1_squared * acos((d * d + r1_squared - r2_squared) / (2 * d * r1));
        double part2 = r2_squared * acos((d * d + r2_squared - r1_squared) / (2 * d * r2));
        double part3 = 0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));
        printf("%.3f\n",area1+area2-(part1+part2-part3));

    }
}
