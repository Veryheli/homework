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
    ~MyCircle();
};
MyCircle::MyCircle():r(0){};
MyCircle::MyCircle(float r):r(r){};
void MyCircle::setR(float r)//类外定义要加上作用域
{
    this->r = r;
}
float MyCircle::getR()
{
    return this->r;
}
float MyCircle::getCir()
{
    return 2*PI*this->r;
}
float MyCircle::getArea()
{
    return PI*this->r*this->r;
}
int main()
{
    cout<<"请输入圆c1和圆c2的半径"<<endl;
    float rc1,rc2;
    cin>>rc1>>rc2;
    MyCircle *c1 = new MyCircle(rc1);
    MyCircle *c2 = new MyCircle();
    c2->setR(rc2);
    cout<<"c1的面积为"<<c1->getArea()<<" c2的面积为"<<c2->getArea()<<endl;
    cout<<"c1的周长为"<<c1->getCir()<<" c2的周长为"<<c2->getCir()<<endl;
    if(c1->getArea() > c2->getArea())
    {
        cout<<"c1圆的面积更大"<<endl;
    }
    else if(c1->getArea() == c2->getArea())
    {
        cout<<"两个圆的面积一样大"<<endl;
    }
    else
    {
        cout<<"c2圆的面积更大"<<endl;
    }
    if(c1->getCir() > c2->getCir())
    {
        cout<<"c1圆的周长更大"<<endl;
    }
    else if(c1->getArea() == c2->getArea())
    {
        cout<<"两个圆的周长一样大"<<endl;
    }
    else
    {
        cout<<"c2圆的周长更大"<<endl;
    }
    return 0;
}

