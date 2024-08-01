#include <iostream>
#include "BudgetMainApp.h"

using namespace std;


int main() {

    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
    budgetMainApp.displayAllUsers();
    budgetMainApp.loginUser();
    budgetMainApp.addIncome();
    budgetMainApp.addExpense();
    budgetMainApp.displayAllIncomes();

}
