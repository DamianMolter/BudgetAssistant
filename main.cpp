#include <iostream>
#include "BudgetMainApp.h"

using namespace std;


int main() {

    BudgetMainApp budgetMainApp("users.xml");
    budgetMainApp.displayAllUsers();
    budgetMainApp.loginUser();
    budgetMainApp.addOperation();
    //budgetMainApp.addOperation();
    budgetMainApp.displayAllIncomes();

}
