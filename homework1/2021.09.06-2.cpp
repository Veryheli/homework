#include <iostream>
using namespace std;
void draw(int n)
{
    int row = 1;//记录当前行数
    int num = 1;//将num的值打印输出，然后将num自增
    for(;row <= n;row++)
    {
        int i = 0;//记录当前行打印的数字个数
        while(i < row)
        {
            cout<<num<<"\t";
            num++;
            i++;
        }
        i = 0;//到下一行重新开始计数
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"输入你要打印几行数字：";
    cin>>n;
    draw(n);
    return 0;
}

