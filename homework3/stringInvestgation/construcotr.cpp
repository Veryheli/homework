//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 16时26分54秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void testConstructor()
{
string s1("test");  // s2 = "test"
string s2(4, 'T');  // s3 = "TTTT"
string s3("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
cout<<"s1="<<s1<<" s2="<<s2<<" s3="<<s3<<endl;
}
int main()
{
    testConstructor();
    return 0;
}
