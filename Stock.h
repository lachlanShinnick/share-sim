#pragma once
#include <string>

class Stock {
public:
    std::string ticker;
    std::string name;
    double price;

    // Default constructor
    Stock() : ticker(""), name(""), price(0.0) {}

    // Parameterized constructor
    Stock(const std::string& ticker, const std::string& name, double price)
        : ticker(ticker), name(name), price(price) {}
};