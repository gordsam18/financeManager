#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <string>
#include <sstream>
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
        std::string displayTransactions() const {
            std::ostringstream oss;
            for (size_t i = 0; i < transactions.size(); ++i) {
                const Transaction& type = transactions[i];
                oss << type.getType() << ": $" << type.getAmount()
                    << " [" << type.getCategory() <<"]\n";
            }
            return oss.str();
        }

        // Summarize totals
        std::string summarize() const {
            double totalIncome = 0, totalExpenses = 0;

            for (size_t i = 0; i < transactions.size(); ++i) {
                const Transaction& type = transactions[i];
                if (type.getType() == "Income") {
                    totalIncome += type.getAmount();
                } else if (type.getType() == "Expense") {
                    totalExpenses += type.getAmount();
                }
            }

            std::ostringstream oss;
            oss << "Total Income: $" << totalIncome << "\n"
                << "Total Expenses: $" << totalExpenses << "\n"
                << "Net Balance: $" << (totalIncome - totalExpenses) << "\n";

            return oss.str();
        }
};

#endif
