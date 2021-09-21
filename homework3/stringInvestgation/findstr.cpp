//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 18时56分22秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void findstr()
{
    string s1("testOHHHHHtestaaa");
    int pos1 = s1.find("test");
    int pos2 = s1.rfind("test");
    cout<<"pos1 = "<<pos1<<"\npos2 = "<<pos2<<endl;
}
int main()
{
    findstr();
    return 0;
}
