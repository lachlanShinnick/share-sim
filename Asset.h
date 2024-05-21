#pragma once
#include <string>

class Asset {
public:
    std::string name;
    double price;

    // Default constructor
    Asset() : name(""), price(0.0) {}

    // Parameterized constructor
    Asset(const std::string& name, double price) : name(name), price(price) {}

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Asset() = default;

    // Pure virtual function to output the name of the asset
    virtual std::string getName() const = 0;

    // Pure virtual function to output the price of the asset
    virtual double getPrice() const = 0;
};
