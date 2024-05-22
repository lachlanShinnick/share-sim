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

    std::string getName() const override {
        return name; 
    }

    double getPrice() const override {
        return price; 
    }
};

