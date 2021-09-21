//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 17时12分33秒
//=============================================================

#include <iostream>
#include <string>
using namespace std;
void test_for_Length()
{
    string s1 = "hellotest";
    int a = s1.length();
    int b = s1.size();
    cout<<"a = "<<a<<" b = "<<b<<endl;

}
int main()
{
    test_for_Length();
   return 0;
}
