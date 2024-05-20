#pragma once
#include "Asset.h"

class Crypto : public Asset {
public:
    // Default constructor
    Crypto() : Asset() {}

    // Parameterized constructor
    Crypto(const std::string& name, double price)
        : Asset(name, price) {}
};
