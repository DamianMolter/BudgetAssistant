#include "BudgetMainApp.h"

void BudgetMainApp :: registerUser(){
    userManager.registerUser();
}

void BudgetMainApp :: loginUser(){
    int loggedUserId = userManager.loginUser();
    if(userManager.isUserLogged()){
        budgetManager = new BudgetManager(loggedUserId, INCOMES_FILE_NAME, EXPENSES_FILE_NAME);
    }
}

void BudgetMainApp :: addIncome(){
    budgetManager->addOperation(INCOMES_FILE_NAME);
}

void BudgetMainApp :: addExpense(){
    budgetManager->addOperation(EXPENSES_FILE_NAME);
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
