//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 18时17分08秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void cal()
{
    string s1("abc");
    string s2("def");
    string s3 = s1.append(s2);
    string s4 = s1.append(s2,1,2);
    string s5 = s1.append(4,'T');
    string s6 = s1.append("ABCD",2,3);
    string s7 = s1 + s2;
    s1 += s2;
    cout<<"s3 = "<<s3<<"\ns4 = "<<s4<<"\ns5 = "<<s5<<"\ns6 = "
        <<s6<<"\ns7 = "<<s7<<"\ns1 = "<<s1<<endl;

}
int main()
{
    cal();
    return 0;
}
