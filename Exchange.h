#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "Market.h"
#include "Crypto.h"

class Exchange : public Market<Crypto> {
public:
    Exchange(const DataHandler& dataHandler);
    void load_quantities(const std::unordered_map<std::string, Crypto>& cryptos) override;
    bool buyAsset(Portfolio& portfolio, const std::string& name, int quantity, const DataHandler& dataHandler) override;
    bool sellAsset(Portfolio& portfolio, const std::string& name, int quantity, const DataHandler& dataHandler) override;
};

#endif // EXCHANGE_H
