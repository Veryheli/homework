#include <iostream>
using namespace std;
void arryRank(int a[],int lenth)
{
    int i,j,*target,temp;//target指针用于遍历数组
    target = &a[0];
    for (i = 0;i < lenth -1 ;i++)
    {
        //用target指针记录最大的元素
        for(j = 0;j < lenth - i;j++)
        {
            if(a[j] > *target)
            {
                target = &a[j];
            }
        }
        j = 0;
        //将最大的元素与最后一个元素交换位置
        if(target != &a[lenth -i -1])
        {
            temp = *target;
            *target = a[lenth - i - 1];
            a[lenth - i -1] = temp;
        }
        target = &a[0];//target指针重新回到起点准备下一次遍历
    }
}
void showArry(int a[],int lenth)
{
    int i;
    for(i = 0;i < lenth;i ++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[10];
    for(int i = 0;i < 10;i++)
    {
        cin>>a[i];
    }
    cout<<"排序前"<<endl;
    showArry(a,10);
    arryRank(a,10);
    cout<<"排序后："<<endl;
    showArry(a,10);
    return 0;
}

