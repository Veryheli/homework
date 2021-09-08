//随机输入1-4之间的整数，统计各数的个数
#include <iostream>
#define MAX_COUNT 10
using namespace std;
void fun()
{
    int i;
    int a[MAX_COUNT];
    cout<<"请输入"<<MAX_COUNT<<"个数"<<endl;
    for (i = 0; i < MAX_COUNT; ++i)
    {
        cin>>a[i];
    }
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    for(i = 0;i < MAX_COUNT; i++)
    {
        if(a[i] == 1)
            count1++;
        else if(a[i] == 2)
            count2++;
        else if (a[i] == 3)
         count3++;
        else if(a[i] == 4)
            count4++;
    }
    cout<<"1的个数为"<<count1<<endl;
    cout<<"2的个数为"<<count2<<endl;
    cout<<"3的个数为"<<count3<<endl;
    cout<<"4的个数为"<<count4<<endl;

}
int main()
{
    fun();
    return 0;
}

