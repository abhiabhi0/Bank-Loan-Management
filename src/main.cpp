#include <fstream>
#include <sstream>
#include <iostream>
#include "bank.h"
#include "user.h"

using namespace std;

void display(std::vector<std::string>& vec, std::string& bank_name)
{
    std::cout << bank_name << " ";
    for (auto& v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[]) {
    /*Sample code to read from file passed as command line argument*/

    //stores bank names and its object in bank_map
    std::unordered_map<std::string, Bank *> banks_map;

    string filename = argv[1];
    ifstream inputFile(filename);

    string cmd;
    while(getline(inputFile, cmd)){
        
        //stores each string from cmd seperatly
        std::vector<std::string> cmd_strs;
        
        //using stringstream to split string
        std::istringstream iss(cmd);
        std::string curr_str;

        while (iss >> curr_str)
        {
            cmd_strs.push_back(curr_str);
        }

        if (cmd_strs[0] == "LOAN")
        {
            //index 1-Bank name, 2-Borrower name, 3-Principal, 4-Years, 5-Rate

            //convert string to int
            double principal = std::stod(cmd_strs[3]); 
            int years = std::stoi(cmd_strs[4]);
            double interest_rate = std::stod(cmd_strs[5]);

            //Insert Bank object in banks_map
            if (banks_map.find(cmd_strs[1]) == banks_map.end())
            {
                Bank* obj = new Bank(cmd_strs[1]);
                banks_map.insert({cmd_strs[1], obj});
            } 

            Bank* bank = banks_map[cmd_strs[1]];
            User* new_borrower = bank->loan(cmd_strs[2], principal, years, interest_rate);

            bank->add_borrower(new_borrower, cmd_strs[2]);
        }
        else if (cmd_strs[0] == "BALANCE")
        {
            
            //index 1-Bank name, 2-Borrower name, 3-emi number

            //convert string to int
            int emi_num = stoi(cmd_strs[3]);
            
            Bank* bank = banks_map[cmd_strs[1]];
            User* borrower = bank->get_borrower(cmd_strs[2]);
            std::vector<std::string> result = bank->balance(borrower, emi_num);

            display(result, cmd_strs[1]);
        }
        else if (cmd_strs[0] == "PAYMENT")
        {
            //index 1-Bank name, 2-Borrower name, 3-lump sum, 4-emi number

            //convert string to int
            double lump_sum = stod(cmd_strs[3]);
            int emi_num = stoi(cmd_strs[4]);

            Bank* bank = banks_map[cmd_strs[1]];
            User* borrower = bank->get_borrower(cmd_strs[2]);

            bank->payment(borrower, lump_sum, emi_num);
        }
        else  
        {
            std::cerr << "Unrecognized Command\n";
        }
    }

    inputFile.close();
    
    return 0;
}
