#ifndef BROKER_H
#define BROKER_H

#include "Market.h"
#include "Stock.h"

class Broker : public Market<Stock> {
public:
    Broker(const DataHandler& dataHandler);
    void load_quantities(const std::unordered_map<std::string, Stock>& stocks) override;
    bool buyAsset(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler) override;
    bool sellAsset(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler) override;
};

#endif // BROKER_H
