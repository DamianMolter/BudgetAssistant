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

void BudgetMainApp :: logoutUser(){
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp :: displayAllUsers(){
    userManager.displayAllUsers();
}
