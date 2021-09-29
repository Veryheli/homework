#pragma once
//股票类，属性有：股票的公司名称、所持股份、单股价格、总价值( = 所持股份×单股价格 )
//包含的方法有：
//1、构造函数，需要传入该股票的公司名
//2、买入股票  和  卖出股票（需要传入买入或卖出的数量）
//3、更改每股价格，股票的价格是一直在变化的
//4、更新当前股票的信息，每次买入或者卖出或者股票的价格改变都会影响到当前股票的信息
//5、获取股票信息，公司名、股份、单股价格、总价值
#include <string>
using namespace std;
class Stock
{
public:
    Stock(string companyName); 
    Stock(); 
    void buyStock(int count);
    void sellStock(int count);
    void setPrice(double price);
    void update();
    string getName();
    int getTotalCount();
    double getPrice();
    double getTotalPrice();
    ~Stock() {}

private:
    string companyName;
    int totalCount;
    double price;
    double total_price;
};

