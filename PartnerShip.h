#ifndef PARTNERSHIP_H
#define PARTNERSHIP_H

#include "Investor.h"
#include <iostream>
#include <fstream>
#include <vector>

class Partnership : public Investor {
private:
    std::vector<std::string> partner_names; // Vector to store the names of the partners

public:
    // Constructor to initialize the balance and partner names
    Partnership(double initial_balance, const std::vector<std::string>& names);

    void Print() override;
    void getInvestorNameOrNames() override;
};

#endif // PARTNERSHIP_H
