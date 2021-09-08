#include <iostream>
#define PI 3.14
using namespace std;
class MyCircle
{
public:
    float r;
    MyCircle(float r);
    MyCircle();
    void setR(float r);
    float getR();
    float getCir();
    float getArea();
};
MyCircle::MyCircle():r(0){};
MyCircle::MyCircle(float r):r(r){};
void MyCircle::setR(float r)
{
    this->r = r;
}
float MyCircle::getR()
{
    return this->r;
}
float MyCircle::getCir()
{
    return 2*PI*r;
}
float MyCircle::getArea()
{
    return PI*r*r;
}
int main()
{
    MyCircle *c1 = new MyCircle(5);
    MyCircle *c2 = new MyCircle();
    c2->setR(2.5);
   //TODO 
    return 0;
}

