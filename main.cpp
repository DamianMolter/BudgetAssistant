#include <iostream>
#include "BudgetMainApp.h"

using namespace std;


int main() {

    BudgetMainApp budgetMainApp("users.xml");
    budgetMainApp.registerUser();
    budgetMainApp.displayAllUsers();

}
