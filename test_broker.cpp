#include <iostream>
#include <cassert>
#include "Broker.h"
#include "Stock.h"
#include "Portfolio.h"
#include "DataHandler.h"

// Function to test Broker
void testBroker() {
    DataHandler dataHandler;

    // Manually populate stock data for testing
    dataHandler.stock_prices_2014["AAPL"] = Stock("AAPL", "Apple Inc.", 150.0);
    dataHandler.stock_prices_2014["GOOGL"] = Stock("GOOGL", "Alphabet Inc.", 1000.0);

    Broker broker(dataHandler);
    Portfolio portfolio(10000.0);

    // Load quantities into the broker
    broker.load_quantities(dataHandler.stock_prices_2014);

    // Test buying stock
    bool buyResult = broker.buyAsset(portfolio, "AAPL", 10, dataHandler);
    std::cout << "Buy result: " << buyResult << std::endl;
    assert(buyResult);
    assert(portfolio.getAssetAmount("Apple Inc.") == 10);
    assert(portfolio.getCash() == 8500.0);

    // Test selling stock
    bool sellResult = broker.sellAsset(portfolio, "AAPL", 5, dataHandler);
    std::cout << "Sell result: " << sellResult << std::endl;
    assert(sellResult);
    assert(portfolio.getAssetAmount("Apple Inc.") == 5);
    assert(portfolio.getCash() == 9250.0);

    std::cout << "Broker tests passed!" << std::endl;
}

int main() {
    testBroker();
    return 0;
}
