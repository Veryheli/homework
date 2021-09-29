#include <iostream>
#include "Stock.h"
using namespace std;
//构造函数，传入公司名，默认其他属性值为零
Stock::Stock()
{

}

Stock::Stock(string companyName)
{
    this->companyName = companyName;
    this->price = 0;
    this->total_price = 0;
    this->totalCount = 0;
}
//买入，买入后更新股票信息
void Stock::buyStock(int count)
{
    this->totalCount += count;
    this->update();
}
//卖出，买入后更新股票信息,还要判断数值是否正确
void Stock::sellStock(int count)
{
    if(count > this->totalCount)
    {
        cout<<"卖出的股票总数不能超过所持总股份！"<<endl;
        return;
    }
    this->totalCount -= count;
    this->update();
}
//设置股票价格
void Stock::setPrice(double price)
{
    this->price = price;
    this->update();
}
//更新股票信息
void Stock::update()
{
    this->total_price = this->price * this->totalCount;
}
//获取股票各个属性的信息
string Stock::getName()
{
    return this->companyName;
}
int Stock::getTotalCount()
{
    return this->totalCount;
}
double Stock::getPrice()
{
    return this->price;
}
double Stock::getTotalPrice()
{
    return this->total_price;
}
