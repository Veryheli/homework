//求两个数的最小公倍数
#include <iostream>
using namespace std;
int cacul(int a,int b)
{
    int result = a > b ? a : b;
    while(result % a != 0 || result % b !=0 )
    {
        result++;
    }
    return result;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"result = "<<cacul(a,b)<<endl;
    return 0;
}

