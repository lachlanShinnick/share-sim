#ifndef INVESTOR_H
#define INVESTOR_H

#include "Portfolio.h"
#include "Broker.h"
#include "Exchange.h"
#include "User.h"

class Investor : public User {
private:
    Portfolio investors_portfolio;

public:
    Investor(double initial_balance);
    virtual ~Investor();
    // virtual functions implemented from User
    bool CheckBalance(double transaction) override;
    void DisplayPortfolio(const DataHandler& dataHandler) override;
    void Buy(Broker& broker, const DataHandler& dataHandler) override;
    void Sell(Broker& broker, const DataHandler& dataHandler) override;
    void BuyCrypto(Exchange& exchange, const DataHandler& dataHandler) override;
    void SellCrypto(Exchange& exchange, const DataHandler& dataHandler) override;
    void GoToNextFinancialYear() override;
    double GetBalance() override;
    int getCurrentYear() const override;
    const Portfolio& getPortfolio() const override;  // Add this method declaration
    // virtual functions every Investor must implement
    virtual void Print() = 0; // Prints the users portfolio to a csv file
    virtual void getInvestorNameOrNames() = 0;
};

#endif // INVESTOR_H