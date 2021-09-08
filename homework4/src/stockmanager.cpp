#include <iostream>
#include <string>
#include "stockmanager.h"
using namespace std;
StockManager::StockManager(string companyName,float price_per_stock)
{
    this->companyName = companyName;
    this->price_per_stock = price_per_stock;
    this->stock_count = 0;
    this->total_price = 0;
}
