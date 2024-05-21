#include "Company.h"

// Constructor to initialize the balance, company name, and board of directors
Company::Company(double initial_balance, const std::string& company_name, const std::vector<std::string>& board)
    : Investor(initial_balance), company_name(company_name), board_of_directors(board) {}

void Company::Print() {
    // Implementation for printing the portfolio to a csv file
    std::ofstream file("company_portfolio.csv");
    if (file.is_open()) {
        file << "Portfolio for Company: " << company_name << "\n";
        file << "Board of Directors:\n";
        for (const auto& director : board_of_directors) {
            file << director << "\n";
        }
        // Example content, you can customize it based on your portfolio details
        file << "Stock,Amount,Price\n";
        // Add actual portfolio details here
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Company::getInvestorNameOrNames() {
    // Implementation for getting the names of the investors
    std::cout << "Company Name: " << company_name << "\n";
    std::cout << "Board of Directors:\n";
    for (const auto& director : board_of_directors) {
        std::cout << director << "\n";
    }
}
