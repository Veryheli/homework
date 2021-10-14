/******************************************************************************
*@ File:             decimal2others.cpp
*
*@ Author:           Chenrenhao
*@ Created:          10/14/21 
*@ Description:      将十进制数转化为2-9进制中任意进制的数
                     使用栈数据类型
*****************************************************************************/
#include <iostream>
using namespace std;
#include <stack>
stack<int> decimal2others(int decimal,int i){ // i为要转化的目标进制,decimal为初始的十进制数
    if(i < 2 || i > 9) throw "输入错误";
    stack<int> target ;//target记录转化的结果
    while(decimal != 0){
        target.push(decimal % i);//余数部分入栈
        decimal = decimal / i;
    }
    return target;
}
int main(){
   int i;
   int decimal;
   stack<int> t;
   cout<<"输入一个十进制数"<<endl;
   cin>>decimal;
   cout<<"输入要转化为一个几进制数"<<endl;
   cin>>i;
   try {
        t = decimal2others(decimal,i);
   }catch(const char * msg) {
        cout<<msg<<endl;
        return -1;
   }
   cout<<"转化之后结果为：";
   while(!t.empty()){
       cout<<t.top();
       t.pop();
   }
   return 0;
}
