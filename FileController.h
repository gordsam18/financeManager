#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include "FinanceManager.h"
#include <iostream>
#include <fstream>

class FileController {
    private:
    std::ofstream MyFile;
    FinanceManager manager;

    public:
    // Constructor
    FileController(const std::string& filename) {
        MyFile.open(filename);
        if (!MyFile.is_open()) {
            std::cerr << "Error: could not open filefor writing.\n";
        }
    }

    // Deconstructor
    ~FileController() {
        if (MyFile.is_open()) {
            MyFile.close();
        }
    }

    // Write to file method
    void writeToFile(const std::string& transactions, const std::string& summary) {
        if (MyFile.is_open()) {
            
            MyFile << "All Transactions: \n" << transactions;
            MyFile << "\n";
            MyFile << "Summary: \n" << summary;

            MyFile.flush();
            
            MyFile.close();
            std::cout << "Data transfer sucessful";
        } else {
            std::cerr << "Error File is not open.\n";
        }
    }

};

#endif
