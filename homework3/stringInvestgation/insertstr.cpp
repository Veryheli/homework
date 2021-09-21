//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 19时16分38秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void insertstr()
{
    string s1("Limitless"), s2("00");
    s1.insert(2, "123");  //在下标 2 处插入字符串"123"，s1 = "Li123mitless"
    cout<<s1<<endl;
    s1.insert(3, s2);  //在下标 2 处插入 s2 , s1 = "Li10023mitless"
    cout<<s1<<endl;
    s1.insert(3, 5, 'X');  //在下标 3 处插入 5 个 'X'，s1 = "Li1XXXXX0023mitless"
    cout<<s1<<endl;
}
int main()
{
    insertstr();
    return 0;
}
