#pragma once
#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;
    BudgetManager *budgetManager;

public:
    BudgetMainApp(string userFileName): userManager(userFileName) {
        budgetManager = NULL;
    };
    ~BudgetMainApp() {
        delete budgetManager;
        budgetManager = NULL;
    }

    void registerUser();
    void loginUser();
    void addOperation();
    void displayAllIncomes();
    void logoutUser();
    void displayAllUsers();


};
