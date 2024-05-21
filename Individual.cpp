#include "Individual.h"

// Constructor to initialize the balance and name
Individual::Individual(double initial_balance, const std::string& investor_name)
    : Investor(initial_balance), name(investor_name) {}

void Individual::Print() {
    // Implementation for printing the portfolio to a csv file
    std::ofstream file("individual_portfolio.csv");
    if (file.is_open()) {
        file << "Portfolio for Individual Investor: " << name << "\n";
        // Example content, you can customize it based on your portfolio details
        file << "Stock,Amount,Price\n";
        // Add actual portfolio details here
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Individual::getInvestorNameOrNames() {
    // Implementation for getting the names of the investors
    std::cout << "Individual Investor Name: " << name << "\n";
}
