#include "bank.h"
#include <iostream>

Bank::Bank(std::string name_)
{
    name = name_;
}

void Bank::loan(std::string& bank_name, std::string& borrower_name, double principal_amt,
      int num_years, double interest)
{
    //total interest = interest/100 * principal * years
    double total_interest = interest / 100 * principal_amt * num_years;

    //total amount = principal + interest
    double total_amt = principal_amt + total_interest;

    //total number of emis = total amount / number of months
    int num_emis = total_amt / (num_years * 12);

    User user(borrower_name, total_amt, num_emis);

    //add this new user in the borrowers map
    borrowers.insert({borrower_name, user});

    for (auto& it : borrowers)
    {
        std::cout << it.first << "\n";
    }
}