#include "Partnership.h"
#include <iostream>
#include <fstream>

Partnership::Partnership(double initial_balance, const std::vector<std::string>& names)
    : Investor(initial_balance), partner_names(names) {
    if (partner_names.size() != 2) {
        throw std::invalid_argument("Partnership must have exactly two partners.");
    }
}

void Partnership::Print(const DataHandler& dataHandler) const {
    const std::string filename = "high_score.txt";
    updateHallOfFame(filename, initial_balance, dataHandler);

    // Load high score and names for printing
    double highScore = 0.0;
    std::string highScoreName;
    loadHighScore(filename, highScore, highScoreName);

    std::cout << "High Score: " << highScore << "%" << std::endl;
    std::cout << "Investor Name(s): " << highScoreName << std::endl;
}

void Partnership::getInvestorNameOrNames() const {
    std::cout << "Partnership Investor Names: " << partner_names[0] << " and " << partner_names[1] << "\n";
}
