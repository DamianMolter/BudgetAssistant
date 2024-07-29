#include "BudgetMainApp.h"

void BudgetMainApp :: registerUser(){
    userManager.registerUser();
}

void BudgetMainApp :: loginUser(){
    int loggedUserId = userManager.loginUser();
    if(userManager.isUserLogged()){
        budgetManager = new BudgetManager(loggedUserId);
    }
}

void BudgetMainApp :: addIncome(){
    budgetManager->addOperation("incomes.xml");
}

void BudgetMainApp :: addExpense(){
    budgetManager->addOperation("expenses.xml");
}

void BudgetMainApp :: displayAllIncomes(){
    budgetManager->displayAllIncomes();
}

void BudgetMainApp :: logoutUser(){
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp :: displayAllUsers(){
    userManager.displayAllUsers();
}
