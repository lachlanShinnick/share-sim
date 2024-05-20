#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <unordered_map>
#include <string>
#include "Stock.h"

class DataHandler {
public:
    // Stock prices for each year [ticker, price]
    std::unordered_map<std::string, Stock> stock_prices_2014;
    std::unordered_map<std::string, Stock> stock_prices_2015;
    std::unordered_map<std::string, Stock> stock_prices_2016;
    std::unordered_map<std::string, Stock> stock_prices_2017;
    std::unordered_map<std::string, Stock> stock_prices_2018;
    std::unordered_map<std::string, Stock> stock_prices_2019;
    std::unordered_map<std::string, Stock> stock_prices_2020;
    std::unordered_map<std::string, Stock> stock_prices_2021;
    std::unordered_map<std::string, Stock> stock_prices_2022;

    int current_year;

    DataHandler();
    Stock getStockByTickerAndYear(const std::string& ticker, int year) const;  
    void loadCSV(const std::string& fileName, std::unordered_map<std::string, Stock>& priceMap);
};

#endif

