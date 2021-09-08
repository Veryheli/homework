#include <iostream>
using namespace std;
//值传递
void solution1(int arr[],int max1,int max2)
{
    int i;
    max1 = arr[0];
    for(i = 0;i < 10;i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if(arr[i] > max2 && arr[i] != max1)
            max2 = arr[i];
    }
}
//引用传递
void solution2(int arr[],int &max1,int &max2)
{  
    int i;
    max1 = arr[0];
    for(i = 0;i < 10;i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if(arr[i] > max2 && arr[i] != max1)
            max2 = arr[i];
    }
}
//指针传递
void solution3(int arr[],int *max1,int *max2)
{
    int i;
    *max1 = arr[0];
    for(i = 0;i < 10;i++)
    {
        if(arr[i] > *max1)
        {
            *max2 = *max1;
            *max1 = arr[i];
        }
        if(arr[i] > *max2 && arr[i] != *max1)
            *max2 = arr[i];
    }
}
int main()
{
    int max1 = 0,max2 = 0;
    int arr[10];
    for(int i = 0; i < 10 ;i ++)
    {
        cin>>arr[i];
    }
    solution1(arr,max1,max2);
    cout<<"值传递得到得结果："<<endl;
    cout<<"最大值："<<max1<<" 第二大值为："<<max2<<endl;
    max1 = 0;
    max2 = 0;
    solution2(arr,max1,max2);
    cout<<"引用递得到得结果："<<endl;
    cout<<"最大值："<<max1<<" 第二大值为："<<max2<<endl;
    max1 = 0;
    max2 = 0;
    solution3(arr,&max1,&max2);
    cout<<"指针传递得到得结果："<<endl;
    cout<<"最大值："<<max1<<" 第二大值为："<<max2<<endl;
    return 0;
}

