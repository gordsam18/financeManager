#include <iostream>
#include <fstream> 
#include "FinanceManager.h"
#include "FileController.h"
#include "UserInputs.h"

using namespace std;


int main() {
    FinanceManager manager;
    FileController fileController("finance_output.txt");
    UserInputs inputs;

    // Get User inputs 
    inputs.getUserInputs();
    manager = inputs.getManager();

    std::cout << manager.displayTransactions() << manager.summarize();

    // Wtite to a file
    fileController.writeToFile(manager.displayTransactions(), manager.summarize());

    return 0;
};
