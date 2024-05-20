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
};
