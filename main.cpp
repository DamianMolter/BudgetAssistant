#include <iostream>
#include "BudgetMainApp.h"

using namespace std;


int main() {

    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
    //budgetMainApp.registerUser();
    budgetMainApp.displayAllUsers();
    budgetMainApp.loginUser();
    budgetMainApp.changePassword();
    budgetMainApp.displayAllUsers();

}
