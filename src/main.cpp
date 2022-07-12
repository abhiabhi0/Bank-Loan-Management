#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "bank.h"

using namespace std;

int main(int argc, char *argv[]) {
    /*Sample code to read from file passed as command line argument*/

    //stores bank names and maps it with bank details
    std::unordered_map<std::string, Bank> banks;

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

            //convert string to double and int
            double principal = std::stod(cmd_strs[3]); 
            int years = std::stoi(cmd_strs[4]);
            double interest_rate = std::stod(cmd_strs[5]);

            //Insert Bank object in map banks
            if (banks.find(cmd_strs[1]) == banks.end())
            {
                Bank obj(cmd_strs[1]);
                banks.insert({cmd_strs[1], obj});
            } 

            Bank bank = banks[cmd_strs[1]];
            bank.loan(cmd_strs[1], cmd_strs[2], principal, years, interest_rate);

        }
        else if (cmd_strs[0] == "BALANCE")
        {

        }
        else if (cmd_strs[0] == "PAYMENT")
        {

        }
        else  
        {
            std::cerr << "Unrecognized Command\n";
        }
    }

    inputFile.close();
    
    return 0;
}
