//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 18时37分50秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void subtest()
{
    string s1 = "abcdefghijklmn";
    string s2 = s1.substr(2,4);
    string s3 = s1.substr(2);
    cout<<"s2 = "<<s2<<"\ns3 = "<<s3<<endl;
}
int main()
{
    subtest();
   return 0;
}
