#ifndef INVESTOR_H
#define INVESTOR_H

#include "User.h"
#include "Portfolio.h"
#include "Broker.h"

class Investor : public User {
protected:
    Portfolio investors_portfolio;
    double balance;

public:
    Investor(double initial_balance);
    virtual ~Investor();

    bool CheckBalance(double transaction);
    void DisplayPortfolio(const DataHandler& dataHandler);
    void Buy(Broker& broker, const DataHandler& dataHandler);
    void Sell(Broker& broker, const DataHandler& dataHandler);
    void GoToNextFinancialYear();
    double GetBalance();
    void Print();
};

#endif
