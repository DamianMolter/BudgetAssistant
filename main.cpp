#include <iostream>
#include "BudgetMainApp.h"

using namespace std;


int main() {

    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!budgetMainApp.isUserLogged()) {
            char choice = budgetMainApp.pickOptionMainMenu();

            switch (choice) {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                budgetMainApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            char choice = budgetMainApp.pickOptionUserMenu();

            switch (choice) {
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.showRecentMonthSummary();
                break;
            case '4':
                budgetMainApp.showLastMonthSummary();
                break;
            case '5':
                budgetMainApp.showCustomSummary();
                break;
            case '6':
                budgetMainApp.changePassword();
                break;
            case '7':
                budgetMainApp.logoutUser();
                break;
            }
        }
    }

}
