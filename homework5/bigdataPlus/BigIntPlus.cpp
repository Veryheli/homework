/******************************************************************************
* File:             BigIntPlus.cpp
*
* Author:           Chenrenhao
* Created:          10/13/21 
* Description:      求两个大数的和，用连式存储结构储存大数
*****************************************************************************/
#include <iostream>
#include <deque> // 用deque储存大整数
using namespace std;
deque<int> add(deque<int> a,deque<int> b){
    int flag = 0,i = 0,m,n; //falg 为进位标志，i为大数的某一位
    deque<int> result;//用来记录运算的结果
    //求大整数a和b的位数
    n = a.size();
    m = b.size();
    //逐位执行加法运算直到某个大整数计算完毕
    while(i < n && i < m){
        result.push_front((a.at(n - i - 1) + b.at(m - i - 1) + flag) % 10); //计算第i位的值
        flag = (a.at(n - i - 1) + b.at(m - i - 1) + flag) / 10; //计算第i位的进位
        i ++;
    }
    //计算大整数b余下的部分
    while(i < m){
        result.push_front( (a.at(n - i - 1) + flag) % 10);
        flag = ( b.at(m - i - 1) + flag) / 10;
        i ++;
    }
    //计算大整数a余下的部分
    while(i < n){
        result.push_front((a.at(n - i - 1) + flag) % 10);
        flag = (a.at(n - i - 1)  + flag) / 10;
            i ++;
    }
    //如果最后有进位，则结果会多一位
    if(flag == 1){
        result.push_front(1);
    }
    return result;
}
int main(){
    deque<int> a;
    deque<int> b;
    for(int i = 0;i < 9 ;i ++){
        a.push_back(i+1);
    }
    for(int i = 0;i < 8 ;i ++){
        b.push_back(i+2);
    }
    deque<int> c = add(a,b);
    for(auto it = a.begin(); it != a.end(); it ++){
        cout<<*it;
    }
    cout<<"+";
    for(auto it = b.begin(); it != b.end(); it ++){
        cout<<*it;
    }
    cout<<"=";
    for(auto it = c.begin();it != c.end();it ++){
        cout<<*it;
    }
    cout<<endl;
    return 0;
}
