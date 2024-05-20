#ifndef INVESTOR_H
#define INVESTOR_H

#include "Portfolio.h"
#include "Broker.h"
#include "Exchange.h"

class Investor {
private:
    Portfolio investors_portfolio;

public:
    Investor(double initial_balance);
    virtual ~Investor();

    bool CheckBalance(double transaction);
    void DisplayPortfolio(const DataHandler& dataHandler);
    void Buy(Broker& broker, const DataHandler& dataHandler);
    void Sell(Broker& broker, const DataHandler& dataHandler);
    void BuyCrypto(Exchange& exchange, const DataHandler& dataHandler);
    void SellCrypto(Exchange& exchange, const DataHandler& dataHandler);
    void GoToNextFinancialYear();
    double GetBalance();
    void Print();
};

#endif // INVESTOR_H
