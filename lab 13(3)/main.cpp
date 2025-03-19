#include <iostream>
class Sphere
{
public:
    Sphere(): radius(0),volume(0),surfaceArea(0){}
    Sphere(double r)
    {
        change_radius(r);
    }
    void set_radius(double r)
    {
        change_radius(r);
    }
    double get_radius()
    {
        return radius;
    }
    double get_volume()
    {
        return volume; 
    }
    double get_surfaceArea()
    {
        return surfaceArea;
    }
private:
    double radius;
    double volume;
    double surfaceArea;
    void change_radius(double r)
    {
        radius = r;
        volume = (4.0 / 3) * acos(-1) * pow(r, 3);
        surfaceArea = 4 * acos(-1) * pow(r, 2);
    }
};


int main()
{
    Sphere mySphere(1);
    std::cout<<"S= "<<mySphere.get_surfaceArea()<<" V= "<<mySphere.get_volume()<<std::endl;
    mySphere.set_radius(5);
    std::cout<<"S= "<<mySphere.get_surfaceArea()<<" V= "<<mySphere.get_surfaceArea();
}
