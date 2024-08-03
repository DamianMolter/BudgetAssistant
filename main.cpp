#include <iostream>
#include "BudgetMainApp.h"

using namespace std;


int main() {

    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
    //budgetMainApp.registerUser();
    budgetMainApp.displayAllUsers();
    budgetMainApp.loginUser();
    //budgetMainApp.addIncome();
    //budgetMainApp.addExpense();
    //budgetMainApp.displayAllIncomes();
    //budgetMainApp.displayAllExpenses();
    budgetMainApp.showRecentMonthSummary();

}
