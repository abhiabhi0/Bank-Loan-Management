#ifndef BANK_H_
#define BANK_H_

#include "user.h"
#include <unordered_map>

class Bank
{
  
    //Bank name
  	std::string name;
    //Map borrower name with his/her loan details
  	std::unordered_map<std::string, User> borrowers;
  public:
    Bank()      = default; //constructor
    Bank(std::string name_); //constructor 
    ~Bank()     = default; //destructor

    //getter and setter method for bank name
    std::string get_bank_name();
    void set_bank_name(std::string&);

    //adds new borrower in the bank
    void add_borrower(User&);

    // User get_borrowers();
    // void set_borrower_details(User&)

    void loan(std::string&, std::string&, double, int, double);

    void payment(std::string&, std::string&, double, int);

    void balance(std::string&, std::string&, int);
};

#endif