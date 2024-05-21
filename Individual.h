#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "Investor.h"
#include <iostream>
#include <fstream>

class Individual : public Investor {
private:
    std::string name; // Member variable to store the name of the individual

public:
    // Constructor to initialize the balance and name
    Individual(double initial_balance, const std::string& investor_name);

    void Print() override;
    void getInvestorNameOrNames() override;
};

#endif // INDIVIDUAL_H
