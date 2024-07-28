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
        lastOperationId = operationFile.getLastId("incomes.xml");
        incomes = operationFile.loadOperations("incomes.xml", LOGGED_USER_ID);
        //expenses = operationFile.loadOperations("expenses.xml", LOGGED_USER_ID);

        /*if(incomes.back().getId() > expenses.back().getId()) {
            lastOperationId = incomes.back().getId();
        } else {
            lastOperationId = expenses.back().getId();
        }*/
    };

    void addOperation(string fileName);
    void displayAllIncomes();


};
