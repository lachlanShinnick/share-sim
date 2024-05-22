#pragma once
#include "Asset.h"

class Stock : public Asset {
public:
    std::string ticker;

    // Default constructor
    Stock() : Asset(), ticker("") {}

    // Parameterized constructor
    Stock(const std::string& ticker, const std::string& name, double price)
        : Asset(name, price), ticker(ticker) {}

    // Implementation of getName for Stock
    std::string getName() const override {
        return name; // Return the name of the stock
    }

    // Implementation of getPrice for Stock
    double getPrice() const override {
        return price; // Return the price of the stock
    }
};

