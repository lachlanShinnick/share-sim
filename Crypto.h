#pragma once
#include "Asset.h"

class Crypto : public Asset {
public:
    // Default constructor
    Crypto() : Asset() {}

    // Parameterized constructor
    Crypto(const std::string& name, double price)
        : Asset(name, price) {}

    // Implementation of getName for Crypto
    std::string getName() const override {
        return name; 
    }

    double getPrice() const override {
        return price; 
    }
};
