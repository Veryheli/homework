//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 19时13分22秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void erasestr()
{
    string s1("Real Steel");
    s1.erase(1, 3);  //删除子串(1, 3)，此后 s1 = "R Steel"
    cout<<s1<<endl;
    s1.erase(5);  //删除下标5及其后面的所有字符，此后 s1 = "R Ste"
    cout<<s1<<endl;
}
int main()
{

    erasestr();
    return 0;
}
