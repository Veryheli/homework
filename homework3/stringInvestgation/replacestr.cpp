//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 19时05分32秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void replacestr()
{
    string s1("Real Steel");
    s1.replace(1, 3, "123456", 2, 4);  //用 "123456" 的子串(2,4) 替换 s1 的子串(1,3)
    cout << s1 << endl;  //输出 R3456 Steel
    string s2("Harry Potter");
    s2.replace(2, 3, 5, 'O');  //用 5 个 '0' 替换子串(2,3)
    cout << s2 << endl;  //输出 HaOOOOO Potter
    int n = s2.find("OOOOO");  //查找子串 "00000" 的位置，n=2
    s2.replace(n, 5, "XXX");  //将子串(n,5)替换为"XXX"
    cout<<s2<<endl;//输出haXXX Potter
}
int main()
{
    replacestr();
    return 0;
}
