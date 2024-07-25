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
    BudgetManager(int loggedUserId): LOGGED_USER_ID(loggedUserId) {
        vector <Operation> incomes = operationFile.loadOperations("incomes.xml");
        vector <Operation> expenses = operationFile.loadOperations("expenses.xml");

        if(incomes.back().getId() > expenses.back().getId()) {
            lastOperationId = incomes.back().getId();
        } else {
            lastOperationId = expenses.back().getId();
        }
    };

    void addIncome();


};
