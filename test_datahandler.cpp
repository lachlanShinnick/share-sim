#include <iostream>
#include <cassert>
#include "DataHandler.h"

// Function to test DataHandler
void testDataHandler() {
    DataHandler dataHandler;
    dataHandler.loadCSV("data/2014.csv", dataHandler.stock_prices_2014);

    // Test loading stock data
    assert(dataHandler.stock_prices_2014.size() > 0);

    // Test retrieving stock by ticker and year
    Stock stock = dataHandler.getStockByTickerAndYear("CBA", 2014);
    assert(stock.name == "COMMONWEALTH BANK OF AUSTRALIA.");
    assert(stock.price == 80.88);

    std::cout << "DataHandler tests passed!" << std::endl;
}

int main() {
    testDataHandler();
    return 0;
}
