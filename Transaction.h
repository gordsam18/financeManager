#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

// Transaction class that applies attributes to a transaction with the Amount, Category, and Type
class Transaction {
private:
    double amount;
    std::string category;
    std::string type;

public:
    // Constructor
    
    Transaction(double amount, const std::string& category, const std::string& type)
        : amount(amount), category(category), type(type) {}

    // Getter
    double getAmount() const { return amount; } // amount is the quantity of money
    std::string getCategory() const { return category; } // category is the bucket it fits into ie rent, food, etc 
    std::string getType() const { return type; } // type is either income or expense

    // Display 
    void display() const{
        std::cout << type << ": " << category << "- $" << amount << '\n';
    }
};

#endif