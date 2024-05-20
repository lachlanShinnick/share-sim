#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Stock.h"
#include "DataHandler.h"
#include <unordered_map>
#include <string>

class Portfolio {
public:
    Portfolio(double initial_cash);

    bool buyAsset(const Stock& stock, double amount, double price);
    bool sellAsset(const std::string& ticker, double amount, double price);
    double getAssetAmount(const std::string& ticker) const;
    void getSummaryOfAssets(const DataHandler& dataHandler) const;
    double getCash() const;
    void incrementYear();
    int getCurrentYear() const;

private:
    std::unordered_map<std::string, std::pair<Stock, double>> assets;
    double cash;
    int current_year;
};

#endif
