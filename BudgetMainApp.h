#pragma once
#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE_NAME, EXPENSES_FILE_NAME;

public:
    BudgetMainApp(string userFileName, string incomesFileName, string expensesFileName)
    :userManager(userFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
        budgetManager = NULL;
    };
    ~BudgetMainApp() {
        delete budgetManager;
        budgetManager = NULL;
    }

    void registerUser();
    void loginUser();
    void addIncome();
    void addExpense();
    void displayAllIncomes();
    void displayAllExpenses();
    void logoutUser();
    void displayAllUsers();



};
