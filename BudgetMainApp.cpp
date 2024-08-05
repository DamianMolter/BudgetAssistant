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

bool BudgetMainApp :: isUserLogged(){
    return userManager.isUserLogged();
}

void BudgetMainApp :: addIncome(){
    budgetManager->addIncome(INCOMES_FILE_NAME);
}

void BudgetMainApp :: addExpense(){
    budgetManager->addExpense(EXPENSES_FILE_NAME);
}

void BudgetMainApp :: showRecentMonthSummary(){
    budgetManager->showRecentMonthSummary();
}

void BudgetMainApp :: showLastMonthSummary(){
    budgetManager->showLastMonthSummary();
}

void BudgetMainApp :: showCustomSummary(){
    budgetManager->showCustomSummary();
}

void BudgetMainApp :: displayAllIncomes(){
    budgetManager->displayAllIncomes();
}

void BudgetMainApp :: displayAllExpenses(){
    budgetManager->displayAllExpenses();
}

void BudgetMainApp :: changePassword(){
    userManager.changePassword();
}

void BudgetMainApp :: logoutUser(){

    userManager.userLogout();
    delete budgetManager;
    budgetManager = NULL;
    cout << "Pomyslnie wylogowao." << endl;
}

void BudgetMainApp :: displayAllUsers(){
    userManager.displayAllUsers();
}

char BudgetMainApp :: pickOptionMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Utils :: loadCharacter();

    return choice;
}

char BudgetMainApp :: pickOptionUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    userManager.displayGreetings();
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Utils :: loadCharacter();

    return choice;
}
