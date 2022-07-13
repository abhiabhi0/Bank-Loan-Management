#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>

class User
{
    //name of user/borrower
  	std::string name;

    //total amount to be paid by user including interest i.e. P+I
  	int total_amt;

    //total number of emis user have to pay
    int num_emis;

    //one emi amount;
    int emi;

    //current lump sum paid
    int lump_sum_paid = 0;
    
    //stores emi from which lump is paid and total lump amount paid at that emi
    std::vector<std::pair<int, int>> lump_payments;

public:
    User()   = default;
    User(std::string name_, int total_amt_, int num_emis_, int emi_) :  name(name_),
                                                        total_amt(total_amt_),
                                                        num_emis(num_emis_),
                                                        emi(emi_)               
                                                        {}
    ~User()  = default;

    //add new lump payment in the lump sum paid and vector lump_payments
    void add_payment(int, int);
};

#endif