#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include "Transaction.h"

// Finace Manager class that adds, displays, and summarizes transactions 
class FinanceManager {
    private:
        std::vector<Transaction>transactions;
    
    public:
        // add a transaction
        void addTransaction(const Transaction& type) {
            transactions.push_back(type);
        }

        // display the transaction 
        void displayTransactions() const {
            for (const auto& type : transactions) {
                type.display();
            }
        }

        // Summarize totals
        void summarize() const {
            double totalIncome = 0, totalExpenses = 0;
            for (const auto& type : transactions) {
                if (type.getType() == "Income") {
                    totalIncome += type.getAmount();
                } else if (type.getType() == "Expense") {
                    totalExpenses += type.getAmount();
                }
            }

            std::cout << "Total Income: $" << totalIncome << "\n"; 
            std::cout << "Total Expenses: $" << totalExpenses<< "\n";
            std::cout << "Balance: $" << totalIncome - totalExpenses<< "\n";

        }

};

#endif
