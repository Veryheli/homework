//==============================================================
// @Author: Chenrenhao
// @Created Time : 2021年09月21日 星期二 18时44分24秒
//=============================================================

#include <iostream>
using namespace std;
void comp()
{
    string s1("hello"), s2("hello, world");
    int n[6];
    n[0]= s1.compare(s2);
    n[1] = s1.compare(1, 2, s2, 0, 3);  //比较s1的子串 (1,2) 和s2的子串 (0,3)
    n[2] = s1.compare(0, 2, s2);  // 比较s1的子串 (0,2) 和 s2
    n[3] = s1.compare("Hello");
    n[4] = s1.compare(1, 2, "Hello");  //比较 s1 的子串(1,2)和"Hello”
    n[5] = s1.compare(1, 2, "Hello", 1, 2);  //比较 s1 的子串(1,2)和 "Hello" 的子串(1,2)
    for(int i = 0;i < 6;i ++)
    {
        cout<<" n"<<'['<<i<<']'<<"="<<n[i]<<endl;
    }

}
int main()
{
    comp();
   return 0;
}
