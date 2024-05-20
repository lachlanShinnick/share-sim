#include "DataHandler.h"
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>  // for std::get_time

int extractYear(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return tm.tm_year + 1900;
}

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
    
    loadCryptoCSV("data/crypto_data.csv");

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

void DataHandler::loadCryptoCSV(const std::string& fileName) {
    std::cout << "loading a crypto" << std::endl;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Could not open the file " << fileName << "!" << std::endl;
        return;
    }

    std::string line;
    bool header = true;
    while (std::getline(file, line)) {
        if (header) {
            header = false; // Skip header
            continue;
        }

        std::stringstream ss(line);
        std::string name, date, priceStr;
        double price;

        // Read Currency_Name
        if (!std::getline(ss, name, ',')) {
            std::cerr << "Error reading currency name from line: " << line << std::endl;
            continue;
        }

        // Read Date
        if (!std::getline(ss, date, ',')) {
            std::cerr << "Error reading date from line: " << line << std::endl;
            continue;
        }

        // Read Price
        if (!std::getline(ss, priceStr, ',')) {
            std::cerr << "Error reading price from line: " << line << std::endl;
            continue;
        }

        // Convert price to double
        try {
            price = std::stod(priceStr);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument for price conversion in line: " << line << " - " << e.what() << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range value for price conversion in line: " << line << " - " << e.what() << std::endl;
            continue;
        }

        // Extract year from date
        int year = extractYear(date);

        // Ensure the year is supported
        if (year < 2014 || year > 2022) {
            std::cerr << "Year not supported: " << year << std::endl;
            continue;
        }

        // Check if this is the first entry for the currency in the year
        auto& cryptoMap = getCryptoMapByYear(year);
        if (cryptoMap.find(name) == cryptoMap.end()) {
            std::cout << "Loaded crypto: " << name << ", Year: " << year << ", Price: " << price << std::endl;  // Debug statement
            cryptoMap[name] = Crypto(name, price);
        }
    }

    file.close();
}

std::unordered_map<std::string, Crypto>& DataHandler::getCryptoMapByYear(int year) {
    switch (year) {
        case 2014: return crypto_prices_2014;
        case 2015: return crypto_prices_2015;
        case 2016: return crypto_prices_2016;
        case 2017: return crypto_prices_2017;
        case 2018: return crypto_prices_2018;
        case 2019: return crypto_prices_2019;
        case 2020: return crypto_prices_2020;
        case 2021: return crypto_prices_2021;
        case 2022: return crypto_prices_2022;
        default: throw std::invalid_argument("Year not supported");
    }
}

Stock DataHandler::getStockByTickerAndYear(const std::string& ticker, int year) const {
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

Crypto DataHandler::getCryptoByCurrencyAndYear(const std::string& currency, int year) const {
    switch (year) {
        case 2014: return crypto_prices_2014.at(currency);
        case 2015: return crypto_prices_2015.at(currency);
        case 2016: return crypto_prices_2016.at(currency);
        case 2017: return crypto_prices_2017.at(currency);
        case 2018: return crypto_prices_2018.at(currency);
        case 2019: return crypto_prices_2019.at(currency);
        case 2020: return crypto_prices_2020.at(currency);
        case 2021: return crypto_prices_2021.at(currency);
        case 2022: return crypto_prices_2022.at(currency);
        default: throw std::invalid_argument("Year not supported");
    }
}

