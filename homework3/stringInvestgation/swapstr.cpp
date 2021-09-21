//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 18时52分02秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void swapstr()
{
    string s1("geigeigei");
    string s2("hahaha");
    s1.swap(s2);
    cout<<"s1 = "<<s1<<"\ns2 = "<<s2<<endl;
}
int main()
{
    swapstr();
   return 0;
}
