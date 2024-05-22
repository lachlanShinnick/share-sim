#ifndef INVESTOR_H
#define INVESTOR_H

#include "Portfolio.h"
#include "Broker.h"
#include "Exchange.h"
#include "User.h"
#include <fstream>
#include <string>

class Investor : public User {
protected:
    Portfolio investors_portfolio;
    double initial_balance;  // Add this member variable

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
    const Portfolio& getPortfolio() const override;

    // virtual functions every Investor must implement
    virtual void Print(const DataHandler& dataHandler) const = 0;  // Add dataHandler as parameter
    virtual void getInvestorNameOrNames() const = 0;

    // New methods for high score functionality
    double calculatePercentageGain(double initial_balance, const DataHandler& dataHandler) const;
    void saveHighScore(const std::string& filename, double initial_balance, const DataHandler& dataHandler) const;
    static bool loadHighScore(const std::string& filename, double& highScore, std::string& name);
    void updateHallOfFame(const std::string& filename, double initial_balance, const DataHandler& dataHandler) const;
};

#endif // INVESTOR_H
