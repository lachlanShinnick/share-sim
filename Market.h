#ifndef MARKET_H
#define MARKET_H

#include "DataHandler.h"
#include "Portfolio.h"
#include <unordered_map>
#include <string>
#include <memory>

template <typename AssetType>
class Market {
protected:
    std::unordered_map<std::string, std::pair<std::shared_ptr<AssetType>, double>> inventory;
    double commission_rate;

public:
    Market(double commissionRate) : commission_rate(commissionRate) {}
    virtual void load_quantities(const std::unordered_map<std::string, AssetType>& assets) = 0;
    virtual bool buyAsset(Portfolio& portfolio, const std::string& symbol, int quantity, const DataHandler& dataHandler) = 0;
    virtual bool sellAsset(Portfolio& portfolio, const std::string& symbol, int quantity, const DataHandler& dataHandler) = 0;
};

#endif
