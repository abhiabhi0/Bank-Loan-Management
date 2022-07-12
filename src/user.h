#ifndef USER_H_
#define USER_H_

#include <string>

class User
{
    //name of user/borrower
  	std::string name;
    //total amount to be paid by user including interest i.e. P+I
  	double total_amt;
    //total number of emis user have to pay
    int emis;

public:
    User()   = default;
    User(std::string name_, double total_amt_, int emis_) :  name(name_),
                                                        total_amt(total_amt_),
                                                        emis(emis_)                  
                                                        {}
    ~User()  = default;
};

#endif