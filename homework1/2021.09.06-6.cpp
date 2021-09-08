#include <iostream>
#include<string>
using namespace std;
void fun(string a)
{
    int pos1 = 0,pos2 = 0;
    int length = 0;
    int targetPos = 0;
    do
    {
        pos2 = a.find(" ",pos1);
        if(pos2 - pos1 >= length)
        {
            length = pos2 - pos1;
            targetPos = pos1;
        }
        pos1 = pos2+1;

    }while(a.find(" ",pos2) != -1);
    cout<<"最长的单词"<<a.substr(targetPos,length)<<endl;
}
int main()
{
    string a;
    getline(cin,a);
    a=a+' ';
    fun(a);
    return 0;
}

