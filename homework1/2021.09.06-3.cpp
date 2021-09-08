#include <iostream>
using namespace std;
void cacul()
{
    float a,b;
    char ch;
    cout<<"输入算式(只能进行两个数的+、-、*、/运算)："<<endl;
    cin>>a>>ch>>b;
    switch(ch)
    {
        case '+':
                     cout<<a<<"+"<<b<<"="<<a+b<<endl;break;
                 
        case '-':
                     cout<<a<<"-"<<b<<"="<<a-b<<endl;break;
                 
        case '*':
                     cout<<a<<"*"<<b<<"="<<a*b<<endl;break;
                 
        case '/':
                     cout<<a<<"/"<<b<<"="<<a/b<<endl;break;
                 
            default:
                cout<<"输入错误！"<<endl;
    }
}
int main()
{
    cacul();
    return 0;
}
