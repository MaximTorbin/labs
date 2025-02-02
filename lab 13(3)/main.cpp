#include <iostream>
class Sphere
{
public:
    double radius;
    double volume;
    double surfaceArea;
    Sphere(): radius(0),volume(0),surfaceArea(0){}
    Sphere(double r)
    {
        setRadius(r);
    }
    void changeRadius(double r)
    {
        setRadius(r);
    }
private:
    void setRadius(double r)
    {
        radius = r;
        volume = (4.0 / 3) * acos(-1) * pow(r, 3);
        surfaceArea = 4 * acos(-1) * pow(r, 2);
    }
};


int main()
{
    Sphere mySphere(1);
    std::cout<<"S= "<<mySphere.surfaceArea<<" V= "<<mySphere.volume<<std::endl;
    mySphere.changeRadius(5);
    std::cout<<"S= "<<mySphere.surfaceArea<<" V= "<<mySphere.volume;
}