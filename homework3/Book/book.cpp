//##############################################################
//# Author: Chenrenhao
//# Created Time : 2021年09月14日 星期二 18时53分35秒
//#=============================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define FILENAME "book.txt"//储存联系人的文件名
#define MAX_COUNT 100//设定通讯录的最大容量
//联系人结构体，包含的数据有姓名和电话号码
struct Person
{
    string name;
    string phoneNumber;
};

//通讯录类，负责管理联系人类
class Book
{
public:
    Book()
    {
        this->personCount = 0;
    }
    void initialize()//负责初始化的函数
    {
        //先判断外部文件是否存在，若存在则读取，否则创建一个新的通讯录
        fstream f(FILENAME,ios::in);
        if(f)
        {
            for(int i = 0;!f.eof();i ++)
            {
                string name;
                string phoneNumber;
                f>>name>>phoneNumber;
                if(!name.empty()&&!phoneNumber.empty())
                {
                    this->data[i].name = name;
                    this->data[i].phoneNumber = phoneNumber;
                    this->personCount++;
                }
            }
            f.close();
        }
        else
        {
            f.open(FILENAME,ios::out);
            cout<<"通讯录为空，已创建一个新的通讯录"<<endl;
            f.close();
        }
    }
    void find(string  target)//通过联系人姓名,或者电话查找联系人
    {
        if(this->personCount == 0)
        {
            cout<<"通讯录为空！"<<endl;
            return;
        }
        int i = 0;
        int resultcount = 0;
        while(i < this->personCount)
        {
            if(this->data[i].name == target||this->data[i].phoneNumber == target)
            {
                resultcount ++;
                cout<<"第"<<resultcount<<"条结果如下:"<<endl;
                cout<<"姓名："<<this->data[i].name<<"\t电话号码："<<this->data[i].phoneNumber<<endl;
            }
            i++;
        }
        if(resultcount == 0)
        {
            cout<<"未查询到相关信息！"<<endl;
        }
    }
    void addPerson()//添加联系人
    {
        string name;
        string phoneNumber;
        cout<<"请输入新建联系人的姓名：";
        cin>>name;
        for(int i = 0; i < this->personCount;i ++)
        {
            if(name == this->data[i].name)
            {
                cout<<"联系人已存在！"<<endl;
                return;
            }
        }
        cout<<name<<"的号码是：";
        cin>>phoneNumber;
        for(int i = 0;i < this->personCount ;i ++)
        {
            if(phoneNumber == this->data[i].phoneNumber)
            {
                cout<<"该号码和联系人："<<this->data[i].name<<" 的号码相同！"<<endl;
                return;
            }
        }
        this->data[this->personCount].name = name;
        this->data[this->personCount].phoneNumber = phoneNumber;
        this->personCount++;
    }
    void showBook()
    {
        int i = 0;
        cout<<"|姓名\t\t| 号码\t\t|"<<endl;
        for(i = 0;i < this->personCount;i ++)
        {
            cout<<"|"<<this->data[i].name<<"\t\t|"<<" "<<this->data[i].phoneNumber<<"\t|"<<endl;
        }
    }
    void save()
    {
        fstream f(FILENAME,ios::out);
        if(f)
        {
            for(int i = 0;i < this->personCount - 1;i ++)
            {
                f<<this->data[i].name<<" "<<this->data[i].phoneNumber<<endl;
            }
            f<<this->data[this->personCount - 1].name<<" "<<this->data[this->personCount - 1].phoneNumber;
        }
        else
        {
            cout<<"文件打卡失败！"<<endl;
        }
        f.close();
    }
    int getPersonCount()
    {
        return this->personCount;
    }
private:
    Person data[MAX_COUNT];
    int personCount;


};
void showMenu()//显示菜单的函数
{
    cout<<"[===================================]"<<endl;
    cout<<"[---------1.显示通讯录--------------]"<<endl;
    cout<<"[---------2.查找联系人--------------]"<<endl;
    cout<<"[---------3.添加联系人--------------]"<<endl;
    cout<<"[---------4.显示菜单----------------]"<<endl;
    cout<<"[---------0.退出程序----------------]"<<endl;
    cout<<"[===================================]"<<endl;

}
void menuLogic(Book &b)
{
    showMenu();
    int ch;//记录用户输入
    bool isRun = true;//记录程序运行状态
    while(isRun)
    {
        cout<<"输入你的操作(输入4显示菜单):";
        cin>>ch;
        switch(ch)
        {
        case 1:{
                   b.showBook();break;
               }
        case 2:{
                   string target;
                   cout<<"输入你要查找的联系人的姓名或者号码：";
                   cin>>target;
                   b.find(target);
                   break;
               }
        case 3:{
                   b.addPerson();break;
               }
        case 4:{
                   showMenu();
                   break;
               }
        case 0:{
                   isRun = false;
                   b.save();//退出时自动保存到文件
                   break;
               }
        default:
               cout<<"输入错误！"<<endl;
        }
    }
}
int main()
{
    Book b;
    b.initialize();
    menuLogic(b);
    return 0;
}

