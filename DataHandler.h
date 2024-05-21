#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <unordered_map>
#include <string>
#include "Stock.h"
#include "Crypto.h"

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

    // Crypto prices for each year [currency, price]
    std::unordered_map<std::string, Crypto> crypto_prices_2014;
    std::unordered_map<std::string, Crypto> crypto_prices_2015;
    std::unordered_map<std::string, Crypto> crypto_prices_2016;
    std::unordered_map<std::string, Crypto> crypto_prices_2017;
    std::unordered_map<std::string, Crypto> crypto_prices_2018;
    std::unordered_map<std::string, Crypto> crypto_prices_2019;
    std::unordered_map<std::string, Crypto> crypto_prices_2020;
    std::unordered_map<std::string, Crypto> crypto_prices_2021;

    int current_year;

    DataHandler();
    Stock getStockByTickerAndYear(const std::string& ticker, int year) const;
    Crypto getCryptoByCurrencyAndYear(const std::string& currency, int year) const;
    std::unordered_map<std::string, Crypto>& getCryptoMapByYear(int year);
    
    void loadCSV(const std::string& fileName, std::unordered_map<std::string, Stock>& priceMap);
    void loadCryptoCSV(const std::string& fileName);
};

#endif
