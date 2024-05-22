#include "Individual.h"
#include <iostream>
#include <fstream>
// Constructor for Individual
Individual::Individual(double initial_balance, const std::string& investor_name)
    : Investor(initial_balance), name(investor_name) {}

// Print high score to the file
void Individual::Print(const DataHandler& dataHandler) const {
    const std::string filename = "high_score.txt";
    updateHallOfFame(filename, initial_balance, dataHandler);

    // Load high score and names for printing
    double highScore = 0.0;
    std::string highScoreName;
    loadHighScore(filename, highScore, highScoreName);

    std::cout << "High Score: " << highScore << "%" << std::endl;
    std::cout << "Investor Name(s): " << highScoreName << std::endl;
}

void Individual::getInvestorNameOrNames() const {
    std::cout << "Individual Investor Name: " << name << "\n";
}
