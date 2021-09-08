#include <iostream>
using namespace std;
int *getMin(int *p1,int *p2,int *p3)
{
    int *pmin = p1;
    if(*p2 < *pmin) pmin = p2;
    if(*p3 < *pmin) pmin = p3;
    return pmin;
}
int main()
{
    int a,b,c;
    int *p;
    cin>>a>>b>>c;
    p = getMin(&a,&b,&c);
    cout<<"最小值为："<<*p<<endl;
    return 0;
}

