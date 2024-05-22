#ifndef COMPANY_H
#define COMPANY_H

#include "Investor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Company : public Investor {
private:
    std::string company_name;               // Variable to store the company name
    std::vector<std::string> board_of_directors; // Vector to store the names of the board of directors

public:
    // Constructor to initialize the balance, company name, and board of directors
    Company(double initial_balance, const std::string& company_name, const std::vector<std::string>& board);

    void Print(const DataHandler& dataHandler) const override;
    void getInvestorNameOrNames() const override;
};

#endif 
