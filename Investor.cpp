#include "Investor.h"
#include <iostream>

// Constructor
Investor::Investor(double initial_balance) : investors_portfolio(initial_balance) {
    std::cout << "Investor initialized.\n";  // Debug statement
}

// Virtual destructor
Investor::~Investor() {}

// Confirms user can afford transaction
bool Investor::CheckBalance(double transaction) {
    return investors_portfolio.getCash() >= transaction;
}

// Displays User's Portfolio on screen
void Investor::DisplayPortfolio(const DataHandler& dataHandler) {
    investors_portfolio.getSummaryOfAssets(dataHandler);
}

// Buys Stock
void Investor::Buy(Broker& broker, const DataHandler& dataHandler) {
    std::string ticker;
    int quantity;

    std::cout << "Enter ticker: ";
    std::cin >> ticker;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    broker.buyAsset(investors_portfolio, ticker, quantity, dataHandler);
}

// Sells Stock
void Investor::Sell(Broker& broker, const DataHandler& dataHandler) {
    std::string ticker;
    int quantity;

    std::cout << "Enter ticker: ";
    std::cin >> ticker;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    broker.sellAsset(investors_portfolio, ticker, quantity, dataHandler);
}

// Buys Crypto
void Investor::BuyCrypto(Exchange& exchange, const DataHandler& dataHandler) {
    std::string name;
    int quantity;

    std::cout << "Enter crypto name: ";
    std::cin >> name;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    exchange.buyAsset(investors_portfolio, name, quantity, dataHandler);
}

// Sells Crypto
void Investor::SellCrypto(Exchange& exchange, const DataHandler& dataHandler) {
    std::string name;
    int quantity;

    std::cout << "Enter crypto name: ";
    std::cin >> name;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    exchange.sellAsset(investors_portfolio, name, quantity, dataHandler);
}

// Increases current year by one
void Investor::GoToNextFinancialYear() {
    investors_portfolio.incrementYear();
    std::cout << "Current year is now: " << investors_portfolio.getCurrentYear() << std::endl;  // Debug statement
}

// Returns Balance
double Investor::GetBalance() {
    return investors_portfolio.getCash();
}

// Prints portfolio to csv (implementation can be expanded)
void Investor::Print() {
    std::cout << "Printing portfolio to CSV... (functionality to be implemented)\n";
}
