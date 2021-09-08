#include <iostream>
template<typename T>
class MyCaculate
{
public:
    T dat;
    MyCaculate(){}
    MyCaculate(int dat):dat(dat){}
    MyCaculate(float dat):dat(dat){}
    MyCaculate(double dat):dat(dat){}

    MyCaculate operator+(const MyCaculate &other)
    {   
        MyCaculate *result = new MyCaculate;
        result->dat = this->dat + other.dat; 
        return *&result;
    }
    MyCaculate operator-(const MyCaculate &other)
    {   
        MyCaculate *result = new MyCaculate;
        result->dat = this->dat - other.dat; 
        return *&result;
    }
    MyCaculate operator*(const MyCaculate &other)
    {   
        MyCaculate *result = new MyCaculate;
        result->dat = this->dat * other.dat; 
        return *&result;
    }
    MyCaculate operator/(const MyCaculate &other)
    {   
        MyCaculate *result = new MyCaculate;
        result->dat = (float)this->dat / (float)other.dat; 
        return *&result;
    }

};
using namespace std;
int main()
{
    cout << "Hello world" << endl;
    return 0;
}

