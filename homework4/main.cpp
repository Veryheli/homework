#include <iostream>
#include "Stock.h"
#include <vector>
#include <algorithm>
#include <fstream>
#define FILENAME "data.txt"
using namespace std;
//需要实现的功能：
//1、菜单界面
//2、显示用户的全部股票信息
//3、将用户的股票信息存储到文件
//4、从文件中读取股票信息
//5、管理用户所持有的股票信息

//展示菜单
void showMenu()
{
    cout<<"\t\t|输入数字选择对应的功能|"<<endl;
    cout<<"\t\t|1、读取我的股份信息   |"<<endl;
    cout<<"\t\t|2、显示股票信息       |"<<endl;
    cout<<"\t\t|3、买入股票           |"<<endl;
    cout<<"\t\t|4、卖出股票           |"<<endl;
    cout<<"\t\t|5、修改股票价格       |"<<endl;
    cout<<"\t\t|6、保存信息           |"<<endl;
    cout<<"\t\t|7、显示菜单           |"<<endl;
    cout<<"\t\t|0、退出程序           |"<<endl;
}
//显示单个股票信息
void showSingalStockInfo(Stock s)
{
    cout<<"|"<<s.getName()<<"\t\t|"<<s.getPrice()<<"\t\t|"<<s.getTotalCount()<<"\t\t|"<<s.getTotalPrice()<<endl;
}
//显示全部股票信息
void showAllStockInfomation(vector<Stock> s)
{
    cout<<"|"<<"股票公司"<<"\t|"<<"单股股值"<<"\t|"<<"所持股数"<<"\t|"<<"股票总值"<<endl;
    for_each(s.begin(),s.end(),showSingalStockInfo);
}
//从文件中保存信息,以二进制读写方便操作
void saveInfo(vector<Stock> &s)
{
    ofstream f;
    f.open(FILENAME,ios::out);
    if(!f.is_open()) 
    {
        cout<<"文件打开失败！"<<endl;
        return;
    }
    for(vector<Stock>::iterator it = s.begin();it != s.end();it ++)
    {
        f<<it->getName()<<" "<<it->getPrice()<<" "<<it->getTotalCount()<<" "<<endl;
    }
    f.close();
    cout<<"文件已写入！"<<endl;
}
//从文件中读取信息
void readInfo(vector<Stock> &s)
{
    ifstream f;
    f.open(FILENAME,ios::in);
    if(!f.is_open())
    {
        cout<<"文件打开失败！"<<endl;
        return;
    }
    string name;
    double price;
    int count;
    double totalPrice;
    while(f>>name&&f>>price&&f>>count)
    {
        Stock t(name);
        t.setPrice(price);
        t.buyStock(count);
        t.update();
        s.push_back(t);
    }
    cout<<"成功读取信息！"<<endl;
    f.close();
}
void menuLogic(vector<Stock> &s)
{
    showMenu();
    int ch;//记录用户输入
    bool isRun = true;//记录程序运行状态
    int flag = 0;
    int count;
    string name;
    double price;
    while(isRun)
    {
        cout<<"------------------------"<<endl;
        cout<<"输入你的选择：";
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    readInfo(s);
                    break;
                }
            case 2:
                {
                    showAllStockInfomation(s);
                    break;
                }
            case 3:
                {
                    cout<<"输入你要买的股票所属的公司名：";
                    cin>>name;
                    //先遍历容器判断用户输入的公司是否存在,并用flag标记
                    for(vector<Stock>::iterator it = s.begin();it != s.end();it ++)
                    {
                        if(!it->getName().compare(name))//两个string相等时返回0
                        {
                            cout<<"请输入要买多少股票:";
                            cin>>count;
                            it->buyStock(count);
                            flag = 1;//一旦查找到匹配的公司名，就把flag标记为1
                            break;
                        }
                    }
                    if(flag != 1)
                    {
                        cout<<"输入股票的价格：";
                        cin>>price;
                        cout<<"输入要买多少股票:";
                        cin>>count;
                        Stock *a = new Stock(name);
                        a->buyStock(count);
                        a->setPrice(price);
                        s.push_back(*a);
                    }
                    flag = 0;//将flag回调为0
                    break;
                }
            case 4:
                {
                    cout<<"输入你要卖出哪种股票:";
                    cin>>name;
                  //先遍历容器判断用户输入的公司是否存在,并用flag标记
                    for(vector<Stock>::iterator it = s.begin();it != s.end();it ++)
                    {
                        if(!it->getName().compare(name))//两个string相等时返回0
                        {
                            cout<<"请输入要卖多少股票:";
                            cin>>count;
                            it->sellStock(count);
                            flag = 1;//一旦查找到匹配的公司名，就把flag标记为1
                            break;
                        }
                    }
                    if(flag != 1)
                    {
                        cout<<"输入有误！"<<endl;
                    }
                    flag = 0;
                    break;
                }
            case 5:
                {  
                    cout<<"输入你要修改哪种股票:";
                    cin>>name;
                  //先遍历容器判断用户输入的公司是否存在,并用flag标记
                    for(vector<Stock>::iterator it = s.begin();it != s.end();it ++)
                    {
                        if(!it->getName().compare(name))//两个string相等时返回0
                        {
                            cout<<"请输入修改后的价格:";
                            cin>>price;
                            it->setPrice(price);
                            flag = 1;//一旦查找到匹配的公司名，就把flag标记为1
                            break;
                        }
                    }
                    if(flag != 1)
                    {
                        cout<<"输入有误！"<<endl;
                    }
                    flag = 0;
                    break;
                }
            case 6:
                {
                    saveInfo(s);
                    break;
                }
            case 7:
                {
                    showMenu();
                    break;
                }
            case 0:
                {
                    isRun = false;
                    cout<<"程序已退出！"<<endl;
                    break;
                }
            default:
                cout<<"输入错误！"<<endl;
                break;
        }
    }
}
int main()
{
    vector<Stock> *s = new vector<Stock>;
    menuLogic(*s);
    return 0;
}

