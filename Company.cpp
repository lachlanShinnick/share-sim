#include "Company.h"
#include <iostream>
#include <fstream>

// Constructor for company
Company::Company(double initial_balance, const std::string& company_name, const std::vector<std::string>& board)
    : Investor(initial_balance), company_name(company_name), board_of_directors(board) {}

// Print the high score of the company
void Company::Print(const DataHandler& dataHandler) const {
    const std::string filename = "high_score.txt";
    updateHallOfFame(filename, initial_balance, dataHandler);

    // Load high score and names for printing
    double highScore = 0.0;
    std::string highScoreName;
    loadHighScore(filename, highScore, highScoreName);

    std::cout << "High Score: " << highScore << "%" << std::endl;
    std::cout << "Investor Name(s): " << highScoreName << std::endl;
}

void Company::getInvestorNameOrNames() const {
    std::cout << "Company Name: " << company_name << "\n";
    std::cout << "Board of Directors:\n";
    for (const auto& director : board_of_directors) {
        std::cout << director << "\n";
    }
}
