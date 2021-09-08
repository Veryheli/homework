#include <iostream>
using namespace std;
void myRank(int *p1,int *p2,int *p3)
{
    int temp;
    int *target = p1;//选择法，target记录选中的最大值
    if(*p2 > *target) target = p2;
    if(*p3 > *target) target = p3;
    //将最大的数据换到最右边
    if(target != p3)
    {
        temp = *target;
        *target = *p3;
        *p3 = temp;
    }
    //再找到*p1和*p2中较大的数据
    target = p1;
    if(*p2 > *target) target = p2;
    //再将*p1和*p2中较大者换在二号位置
    if(target != p2)
    {
        temp = *target;
        *target = *p2;
        *p2 = temp;
    }//此时剩下的*p1为最小值
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    myRank(&a,&b,&c);
    cout<<"after myRank..."<<endl;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    return 0;
}

