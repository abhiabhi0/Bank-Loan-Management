#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include <unordered_map>

class User
{
    //name of user/borrower
  	std::string name;

    //total amount to be paid by user including interest i.e. P+I
  	double total_amt;

    //total number of emis user have to pay
    double total_emis;

    //one emi amount;
    double emi_amt;

    //current lump sum paid
    double lump_sum_paid = 0;
    
    //map emi from which lump is paid to total lump amount paid at that emi
    std::unordered_map<int, double> emi_lump_map;

    //stores emi from which lump is paid. It stores emi+1
    std::vector<int> lump_emis = {};
  public:
    User()   = default;
    User(std::string name_, double total_amt_, double total_emis_, double emi_amt_) :  name(name_),
                                                        total_amt(total_amt_),
                                                        total_emis(total_emis_),
                                                        emi_amt(emi_amt_)               
                                                        {}
    ~User()  = default;

    //add new lump payment in the lump sum paid and vector lump_payments
    void add_payment(double, int);

    //returns total amount
    double get_total_amount();

    //returns one emi amount
    double get_emi_amount();
    //updates one emi amount
    void set_emi_amount(double);

    //returns total number of emis
    double get_total_emis();

    //returns lump amount paid till this emi
    double lump_amt_paid(int);

    std::string get_name()
    {
        return name;
    }
};

#endif