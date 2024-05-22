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
}

void Individual::getInvestorNameOrNames() const {
    std::cout << "Individual Investor Name: " << name << "\n";
}
