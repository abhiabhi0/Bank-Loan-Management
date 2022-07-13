#include "bank.h"
#include <iostream>
#include <cmath>

Bank::Bank(std::string name_)
{
    name = name_;
}

void Bank::add_borrower(User& user, std::string& borrower_name)
{
    //add this new user in the borrowers map
    borrowers.insert({borrower_name, user});
}

User Bank::get_borrower(std::string& borrower_name)
{
    return borrowers[borrower_name];
}

void Bank::loan(std::string& bank_name, std::string& borrower_name, int principal_amt,
      int num_years, int interest)
{
    //total interest = interest/100 * principal * years
    int total_interest = interest / 100 * principal_amt * num_years;

    //total amount = principal + interest
    int total_amt = principal_amt + total_interest;

    //total number of emis = total amount / number of months
    int num_emis = ceil(num_years * 12);

    //amount of one emi
    int emi_amt = ceil(total_amt/num_emis);

    User user(borrower_name, total_amt, num_emis, emi_amt);

    add_borrower(user, borrower_name);
}

void Bank::payment(std::string& bank_name, std::string& borrower_name, int lump_sum, int emi_num)
{
    //obj of user class stores details of user with name = borrower_name
    User borrower = get_borrower(borrower_name);

    borrower.add_payment(lump_sum, emi_num);
}