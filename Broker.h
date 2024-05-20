#ifndef BROKER_H
#define BROKER_H

#include "DataHandler.h"
#include "Portfolio.h"
#include <unordered_map>
#include <string>

class Broker {
private:
    std::unordered_map<std::string, std::pair<Stock, double>> inventory;
    double commission_rate;

public:
    Broker(const DataHandler& dataHandler);
    void load_quantities(const std::unordered_map<std::string, Stock>& stocks);
    bool buyStock(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler);
    bool sellStock(Portfolio& portfolio, const std::string& ticker, int quantity, const DataHandler& dataHandler);
};

#endif // BROKER_H
