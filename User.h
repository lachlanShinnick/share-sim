#ifndef USER_H
#define USER_H

#include <string>
#include "Portfolio.h"
#include "Broker.h"
#include "Exchange.h"
#include "DataHandler.h"

class User {
public:
    // Constructor
    User() = default;

    // Virtual destructor
    virtual ~User() = default;

    // Other pure virtual functions that `Investor` and its derived classes need to implement
    virtual bool CheckBalance(double transaction) = 0;
    virtual void DisplayPortfolio(const DataHandler& dataHandler) = 0;
    virtual void Buy(Broker& broker, const DataHandler& dataHandler) = 0;
    virtual void Sell(Broker& broker, const DataHandler& dataHandler) = 0;
    virtual void BuyCrypto(Exchange& exchange, const DataHandler& dataHandler) = 0;
    virtual void SellCrypto(Exchange& exchange, const DataHandler& dataHandler) = 0;
    virtual void GoToNextFinancialYear() = 0;
    virtual double GetBalance() = 0;
    virtual int getCurrentYear() const = 0;
    virtual const Portfolio& getPortfolio() const = 0;
};

#endif // USER_H
