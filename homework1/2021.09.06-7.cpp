#include <iostream>
using namespace std;
int fun(int day)
{
    if(day == 10) return 1;
    return (fun(day+1)+1)*2;
}
int main()
{
    cout << "第一天有" <<fun(1)<<"个桃子"<< endl;
    return 0;
}
