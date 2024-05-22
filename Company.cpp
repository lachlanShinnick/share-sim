#include "Company.h"
#include <iostream>
#include <fstream>

Company::Company(double initial_balance, const std::string& company_name, const std::vector<std::string>& board)
    : Investor(initial_balance), company_name(company_name), board_of_directors(board) {}

void Company::Print(const DataHandler& dataHandler) const {
    const std::string filename = "high_score.txt";
    updateHallOfFame(filename, initial_balance, dataHandler);
}

void Company::getInvestorNameOrNames() const {
    std::cout << "Company Name: " << company_name << "\n";
    std::cout << "Board of Directors:\n";
    for (const auto& director : board_of_directors) {
        std::cout << director << "\n";
    }
}
