#ifndef STOCK_MANAGER_H
#define STOCK_MANAGER_H
#include <string>
using namespace std;
class StockManager
{
public:
    string companyName;
    int stock_count;
    float price_per_stock;
    float total_price;
    StockManager( string companyName,float price_per_stock );
    ~StockManager();
    void getStocks(int count);
    void buyStocks(int count);
    void sellStocks(int count);
    void showInfo();

private:

};
#endif
