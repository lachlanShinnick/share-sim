#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Asset.h"
#include "DataHandler.h"
#include <unordered_map>
#include <string>
#include <memory>

class Portfolio {
private:
    std::unordered_map<std::string, std::pair<std::shared_ptr<Asset>, double>> assets;
    double cash;
    int current_year;

public:
    Portfolio(double initial_cash);

    bool buyAsset(const std::shared_ptr<Asset>& asset, double amount, double price);
    bool sellAsset(const std::string& name, double amount, double price);
    double getAssetAmount(const std::string& name) const;
    void getSummaryOfAssets(const DataHandler& dataHandler) const;
    double getCash() const;
    void incrementYear();
    int getCurrentYear() const;
    double calculateTotalAssetsValue(const DataHandler& dataHandler) const;  // Add this method declaration
};

#endif // PORTFOLIO_H

