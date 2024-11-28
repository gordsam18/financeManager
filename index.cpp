#include <iostream>
#include "FinanceManager.h"

using namespace std;


int main() {
    FinanceManager manager;

    double amount;
    std::string category;
    std::string type;

    bool stop = false;
    char answer;

    while(!stop) {

        std::cout << "Enter amount: ";
        std::cin >> amount;
        std::cout << "Input Category: ";
        std::cin >> category;
        std::cout << "Is it income or expense?: ";
        std::cin >> type;
        manager.addTransaction(Transaction(amount, category, type));
        std::cout << "Do you have another transaction? (y/n): ";
        std::cin >> answer;
        if (answer == 'n') {
            std::cout << "Thank you.\n";
            stop = true;
        };
    };
 
    /*
    // test cases
    manager.addTransaction(Transaction(1000, "Salary", "Income"));
    manager.addTransaction(Transaction(200, "Groceries", "Expense"));
    manager.addTransaction(Transaction(50, "Utilities", "Expense"));
    */
   
    // Display transactions
    std::cout << "All Transactions:\n";
    manager.displayTransactions();

    // Display summary
    std::cout << "\nSummary:\n";
    manager.summarize();

    return 0;
};
