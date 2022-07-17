#include "bank.h"
#include <cmath>

Bank::Bank(std::string name_)
{
    name = name_;
}

void Bank::add_borrower(User* borrower, std::string borrower_name)
{
    //add this new user in the borrowers map
    borrowers_map.insert({borrower_name, borrower});
}

User* Bank::get_borrower(std::string borrower_name)
{
    return borrowers_map[borrower_name];
}

User* Bank::loan(std::string borrower_name, double principal_amt,
      int num_years, double interest)
{
    //total interest = interest/100 * principal * years
    double total_interest = (interest * principal_amt * num_years) / 100;

    //total amount = principal + interest
    double total_amt = principal_amt + total_interest;

    //total number of emis = total amount / number of months
    double num_emis = num_years * 12;

    //amount of one emi
    double emi_amt = ceil(total_amt/num_emis);

    //new borrower object
    User* user = new User(borrower_name, total_amt, num_emis, emi_amt);

    return user;
}

void Bank::payment(User* borrower, double lump_sum, int emi_num)
{
    //obj of user class stores details of user with name = borrower_name

    borrower->add_payment(lump_sum, emi_num);
}

std::vector<std::string> Bank::balance(User* borrower, int emi_num)
{
    //stores output to be displayed in string format    
    std::vector<std::string> output_res;
    output_res.push_back(borrower->get_name());

    double total_amt = borrower->get_total_amount();

    //single emi amount
    double one_emi_amt = ceil(borrower->get_emi_amount());

    //amount paid in emis only
    double amt_in_emis = emi_num * one_emi_amt;

    //amount paid in lump sum till emi_num
    double total_lump_sum = borrower->lump_amt_paid(emi_num);

    double total_amt_paid = amt_in_emis + total_lump_sum;

    double rem_amt = total_amt - total_amt_paid;
    if (rem_amt < 0) rem_amt = 0; //more than total amount is paid bcoz of rounding numbers

    double rem_emi = ceil(rem_amt / one_emi_amt); 
    if (rem_emi < 0) rem_emi = 0;

    if (rem_amt < one_emi_amt) //remaining sum is less than emi amount
    {
        borrower->set_emi_amount(rem_amt);   
        rem_emi = 1;
    }

    //inserting remaining amount and remaining number of emis in output_res
    output_res.push_back(std::to_string(int(total_amt_paid)));
    output_res.push_back(std::to_string(int(rem_emi)));

    return output_res;
}