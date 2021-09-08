#include <iostream>
using namespace std;
float add(float a,float b)
{
    return a + b;
}
float sub(float a,float b)
{
    return a - b;
}
float multi(float a,float b)
{
    return a * b;
}
float division(float a,float b)
{
    return (float)a/(float)b;
}
float main()
{
    int ch;
    float a,b;
    cout<<"输入1进行加法"<<endl;
    cout<<"输入2进行减法"<<endl;
    cout<<"输入3进行乘法"<<endl;
    cout<<"输入4进行除法"<<endl;
    cin>>ch;
    cin>>a>>b;
    switch(ch)
    {
        case 1:{cout<<a<<"+"<<b<<"="<<add(a,b)<<endl;break;}
        case 2:{cout<<a<<"-"<<b<<"="<<sub(a,b)<<endl;break;}
        case 3:{cout<<a<<"x"<<b<<"="<<multi(a,b)<<endl;break;}
        case 4:{cout<<a<<"/"<<b<<"="<<division(a,b)<<endl;break;}
    }
    return 0;
}

