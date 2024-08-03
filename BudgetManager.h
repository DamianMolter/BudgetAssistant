#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
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
    void displayOperation(size_t index, vector <Operation> operations);

public:
    BudgetManager(int loggedUserId, string incomesFileName, string expensesFileName): LOGGED_USER_ID(loggedUserId) {
        lastOperationId = operationFile.getLastId(incomesFileName, expensesFileName);
        incomes = operationFile.loadOperations(incomesFileName, LOGGED_USER_ID);
        expenses = operationFile.loadOperations(expensesFileName, LOGGED_USER_ID);
        sort(incomes.begin(), incomes.end(), DateMethods :: compareDates);
        sort(expenses.begin(), expenses.end(), DateMethods :: compareDates);
    };

    void addIncome(string fileName);
    void addExpense(string fileName);
    void showRecentMonthSummary();
    void displayAllIncomes();   //test
    void displayAllExpenses();  //test


};
