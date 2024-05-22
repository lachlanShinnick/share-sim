#include <iostream>
#include <cassert>
#include "Portfolio.h"
#include "Stock.h"
#include "Crypto.h"
#include "DataHandler.h"

// Function to test Portfolio
void testPortfolio() {
    Portfolio portfolio(10000.0);
    auto stock = std::make_shared<Stock>("AAPL", "Apple Inc.", 150.0);
    auto crypto = std::make_shared<Crypto>("Bitcoin", 40000.0);

    // Test buying stock
    assert(portfolio.buyAsset(stock, 10, 150.0));
    assert(portfolio.getAssetAmount("Apple Inc.") == 10);
    assert(portfolio.getCash() == 8500.0);

    // Test selling stock
    assert(portfolio.sellAsset("Apple Inc.", 5, 150.0));
    assert(portfolio.getAssetAmount("Apple Inc.") == 5);
    assert(portfolio.getCash() == 9250.0);

    // Test buying crypto
    assert(portfolio.buyAsset(crypto, 0.1, 40000.0));
    assert(portfolio.getAssetAmount("Bitcoin") == 0.1);
    assert(portfolio.getCash() == 5250.0);

    // Test selling crypto
    assert(portfolio.sellAsset("Bitcoin", 0.05, 40000.0));
    assert(portfolio.getAssetAmount("Bitcoin") == 0.05);
    assert(portfolio.getCash() == 7250.0);

    std::cout << "Portfolio tests passed!" << std::endl;
}

int main() {
    testPortfolio();
    return 0;
}
