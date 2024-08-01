#pragma once
#include <iostream>
#include <vector>
#include "OperationFile.h"
#include "DateMethods.h"
#include "Utils.h"

using namespace std;

class BudgetManager {

    const int LOGGED_USER_ID;
    int lastOperationId;
    OperationFile operationFile;
    vector <Operation> incomes;
    vector <Operation> expenses;
    Operation giveNewOperationData(int loggedUserId);

public:
    BudgetManager(int loggedUserId, string incomesFileName, string expensesFileName): LOGGED_USER_ID(loggedUserId) {
        lastOperationId = operationFile.getLastId(incomesFileName, expensesFileName);
        incomes = operationFile.loadOperations(incomesFileName, LOGGED_USER_ID);
        expenses = operationFile.loadOperations(expensesFileName, LOGGED_USER_ID);
    };

    void addOperation(string fileName);
    void displayAllIncomes();


};
