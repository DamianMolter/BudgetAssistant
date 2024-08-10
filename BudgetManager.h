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
    int lastIncomeId;
    int lastExpenseId;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;
    Operation giveNewOperationData(int loggedUserId, int lastOperationId);
    void displayOperation(size_t index, vector <Operation> operations);
    void showSummary(int beginOfMonth, int endOfMonth);
    string insertDate();

public:
    BudgetManager(int loggedUserId, string incomesFileName, string expensesFileName): LOGGED_USER_ID(loggedUserId) {
        lastIncomeId = incomeFile.getLastIdFromFile(incomesFileName);
        lastExpenseId = expenseFile.getLastIdFromFile(expensesFileName);
        incomes = incomeFile.loadOperations(incomesFileName, LOGGED_USER_ID);
        expenses = expenseFile.loadOperations(expensesFileName, LOGGED_USER_ID);
        sort(incomes.begin(), incomes.end(), DateMethods :: compareDates);
        sort(expenses.begin(), expenses.end(), DateMethods :: compareDates);
    };

    void addIncome(string fileName);
    void addExpense(string fileName);
    void showRecentMonthSummary();
    void showLastMonthSummary();
    void showCustomSummary();
    void displayAllIncomes();   //test
    void displayAllExpenses();  //test


};
