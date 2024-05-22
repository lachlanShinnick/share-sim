#include <iostream>
#include <cassert>
#include "Exchange.h"
#include "Crypto.h"
#include "Portfolio.h"
#include "DataHandler.h"

// Function to test Exchange
void testExchange() {
    DataHandler dataHandler;

    // Manually populate crypto data for testing
    dataHandler.crypto_prices_2014["Bitcoin"] = Crypto("Bitcoin", 5.0);
    dataHandler.crypto_prices_2014["Ethereum"] = Crypto("Ethereum", 10.0);

    Exchange exchange(dataHandler);
    Portfolio portfolio(10000.0);

    // Load quantities into the exchange
    exchange.load_quantities(dataHandler.crypto_prices_2014);

    // Test buying crypto
    assert(exchange.buyAsset(portfolio, "Bitcoin", 1, dataHandler));
    assert(portfolio.getAssetAmount("Bitcoin") == 1);
    assert(portfolio.getCash() < 10000.0);

    // Test selling crypto
    assert(exchange.sellAsset(portfolio, "Bitcoin", 1, dataHandler));
    assert(portfolio.getAssetAmount("Bitcoin") == 0);
    assert(portfolio.getCash() > 5000.0);

    std::cout << "Exchange tests passed!" << std::endl;
}

int main() {
    testExchange();
    return 0;
}