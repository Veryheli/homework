#include <iostream>
#include<string>
using namespace std;
void fun(string a)
{
    int pos1 = 0,pos2 = 0;//pos1和pos2分别记录一个单词的起始位置和结束位置
    int length = 0;//记录当前单词长度
    int targetPos = 0;//指向最长的单词
    do
    {
        pos2 = a.find(" ",pos1);//按空格为标志识别句子中的单词
        if(pos2 - pos1 >= length)
        {
            length = pos2 - pos1;//获取单词长度
            targetPos = pos1;
        }
        pos1 = pos2+1;//略过空格

    }while(a.find(" ",pos2) != -1);
    cout<<"最长的单词"<<a.substr(targetPos,length)<<endl;//从原来string中截取找到的最长单词
}
int main()
{
    string a;//使用string容器储存用户输入
    getline(cin,a);//由于输入的字符串带空格，用getline函数输入
    a=a+' ';//由于程序按空格分隔单词，需要再字符串结尾添加空格才能正确识别所有单词
    fun(a);
    return 0;
}

