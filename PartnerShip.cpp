#include "Partnership.h"

// Constructor to initialize the balance and partner names
Partnership::Partnership(double initial_balance, const std::vector<std::string>& names)
    : Investor(initial_balance), partner_names(names) {
    if (partner_names.size() != 2) {
        throw std::invalid_argument("Partnership must have exactly two partners.");
    }
}

void Partnership::Print() {
    // Implementation for printing the portfolio to a csv file
    std::ofstream file("partnership_portfolio.csv");
    if (file.is_open()) {
        file << "Portfolio for Partnership Investors: " << partner_names[0] << " and " << partner_names[1] << "\n";
        // Example content, you can customize it based on your portfolio details
        file << "Stock,Amount,Price\n";
        // Add actual portfolio details here
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Partnership::getInvestorNameOrNames() {
    // Implementation for getting the names of the investors
    std::cout << "Partnership Investor Names: " << partner_names[0] << " and " << partner_names[1] << "\n";
}
