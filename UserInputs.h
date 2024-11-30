#ifndef USERINPUTS_h
#define USERINPUTS_h

#include "FinanceManager.h"
#include <iostream>
#include <string>

using namespace std;

class UserInputs {
    private:
        FinanceManager manager;
    
        

    public:
        double amount;
        std::string category;
        std::string type;

        bool stop = false;
        char moreInputs;
     
        
        void getUserInputs() {

            while(!stop) {
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Input Category: ";
                std::cin >> category;
                std::cout << "Is it income or expense?: ";
                std::cin >> type;
                manager.addTransaction(Transaction(amount, category, type));
                std::cout << "Do you have another transaction? (y/n): ";
                std::cin >> moreInputs;
                if (moreInputs == 'n') {
                    std::cout << "Thank you.\n";
                    stop = true;
                }
            }
        }
        FinanceManager& getManager() {
            return manager;
        }

};

#endif