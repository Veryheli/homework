#include <iostream>
using namespace std;
int fun(int day)//递归函数，函数功能为求day天时有几个桃子
{
    if(day == 10) return 1;//第10天有一个
    return (fun(day+1)+1)*2;//相邻两天桃子数量关系
}
int main()
{
    cout << "第一天有" <<fun(1)<<"个桃子"<< endl;
    return 0;
}
