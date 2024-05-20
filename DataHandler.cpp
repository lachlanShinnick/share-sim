#include "DataHandler.h"
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor
DataHandler::DataHandler() {
    std::cout << "Constructor Data Handler " << std::endl;
    loadCSV("data/2014.csv", stock_prices_2014);
    loadCSV("data/2015.csv", stock_prices_2015);
    loadCSV("data/2016.csv", stock_prices_2016);
    loadCSV("data/2017.csv", stock_prices_2017);
    loadCSV("data/2018.csv", stock_prices_2018);
    loadCSV("data/2019.csv", stock_prices_2019);
    loadCSV("data/2020.csv", stock_prices_2020);
    loadCSV("data/2021.csv", stock_prices_2021);
    loadCSV("data/2022.csv", stock_prices_2022);
    current_year = 2014;
}

void DataHandler::loadCSV(const std::string& fileName, std::unordered_map<std::string, Stock>& stockMap) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Could not open the file " << fileName << "!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string ticker, name, priceStr;
        double price;

        // Read ticker
        if (!std::getline(ss, ticker, ',')) {
            std::cerr << "Error reading ticker from line: " << line << std::endl;
            continue;
        }

        // Read name
        if (!std::getline(ss, name, ',')) {
            std::cerr << "Error reading name from line: " << line << std::endl;
            continue;
        }

        // Read price
        if (!std::getline(ss, priceStr, ',')) {
            std::cerr << "Error reading price from line: " << line << std::endl;
            continue;
        }

        // Convert price to double
        try {
            if (priceStr == "-") {
                price = 0.0;  // or any value you want to represent missing data
            } else {
                price = std::stod(priceStr);
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument for price conversion in line: " << line << " - " << e.what() << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range value for price conversion in line: " << line << " - " << e.what() << std::endl;
            continue;
        }

        // Create a Stock object and insert into the map
        Stock stock(ticker, name, price);
        stockMap[ticker] = stock;
        std::cout << "Loaded stock: " << ticker << ", " << name << ", " << price << std::endl;  // Debug statement
    }

    file.close();
}

Stock DataHandler::getStockByTickerAndYear(const std::string& ticker, int year) const{
    switch (year) {
        case 2014: return stock_prices_2014.at(ticker);
        case 2015: return stock_prices_2015.at(ticker);
        case 2016: return stock_prices_2016.at(ticker);
        case 2017: return stock_prices_2017.at(ticker);
        case 2018: return stock_prices_2018.at(ticker);
        case 2019: return stock_prices_2019.at(ticker);
        case 2020: return stock_prices_2020.at(ticker);
        case 2021: return stock_prices_2021.at(ticker);
        case 2022: return stock_prices_2022.at(ticker);
        default: throw std::invalid_argument("Year not supported");
    }
}
