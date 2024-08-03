#include "BudgetManager.h"

void BudgetManager :: addIncome(string fileName) {

    system("cls");
    cout << ">>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Operation operation = giveNewOperationData(LOGGED_USER_ID);
    incomes.push_back(operation);
    operationFile.addOperationToFile(operation, fileName);
    lastOperationId++;
}

void BudgetManager :: addExpense(string fileName) {

    system("cls");
    cout << ">>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Operation operation = giveNewOperationData(LOGGED_USER_ID);
    expenses.push_back(operation);
    operationFile.addOperationToFile(operation, fileName);
    lastOperationId++;
}

void BudgetManager :: showRecentMonthSummary() {

    int beginOfRecentMonth = DateMethods :: getRecentMonthBegin();
    int endOfRecentMonth = beginOfRecentMonth + DateMethods :: calculateRecentMonthLength() + 1;
    float incomeSum = 0.00;
    float expenseSum = 0.00;

    cout << "==============================" << endl;
    cout << "WYKAZ PRZYCHODOW:" << endl;
    for (size_t i = 0; i < incomes.size(); i++) {
        if(incomes[i].getDate() > beginOfRecentMonth && incomes[i].getDate() < endOfRecentMonth) {
            displayOperation(i, incomes);
            incomeSum += incomes[i].getAmount();
        }
    }
    cout << "==============================" << endl;
    cout << "WYKAZ WYDATKOW:" << endl;
    for (size_t j = 0; j < expenses.size(); j++) {
        if(expenses[j].getDate() > beginOfRecentMonth && expenses[j].getDate() < endOfRecentMonth){
            displayOperation(j, expenses);
            expenseSum += expenses[j].getAmount();
        }
    }


    cout << "Suma przychodow to: " << fixed << setprecision(2) << incomeSum << endl;
    cout << "Suma wydatkow to: " << expenseSum << endl;
    cout << "Bilans za biezacy miesiac to: " << incomeSum - expenseSum << endl;
}

Operation BudgetManager :: giveNewOperationData(int loggedUserId) {
    Operation operation;
    string input;
    int date;
    string item;
    string amount;
    operation.setId(lastOperationId + 1);
    operation.setUserId(LOGGED_USER_ID);

    if(DateMethods :: wantedTodayDate()) {
        input = DateMethods :: loadTodayDate();
    } else {

        cout << "Podaj date: ";
        input = Utils :: loadLine();
        while(!DateMethods :: isDateCorrect(input)) {
            cout << "Data jest nieprawidlowa! Podaj ponownie date!" << endl;
            input = Utils :: loadLine();
        }

    }


    operation.setUserDate(input);
    date = DateMethods :: convertDateToNumericForm(input);
    operation.setDate(date);

    cout << "Podaj tytul: ";
    input = Utils :: loadLine();
    operation.setItem(input);

    cout << "Podaj kwote: ";
    input = Utils:: loadLine();
    input = Utils :: changeComaToDot(input);
    operation.setAmount(stof(input));

    return operation;
}

void BudgetManager :: displayAllIncomes() {
    cout << "==============================" << endl;
    cout << "WYKAZ PRZYCHODOW:" << endl;
    for(size_t i = 0; i < incomes.size(); i++) {
        cout << "Id operacji: " << incomes[i].getId() << endl;
        cout << "Data operacji: " << incomes[i].getUserDate() << endl;
        cout << "Tytul operacji: " << incomes[i].getItem() << endl;
        cout << "Kwota: " << incomes[i].getAmount() << endl << endl;
    }

}

void BudgetManager :: displayAllExpenses() {
    cout << "==============================" << endl;
    cout << "WYKAZ WYDATKOW:" << endl;
    for(size_t i = 0; i < expenses.size(); i++) {
        cout << "Id operacji: " << expenses[i].getId() << endl;
        cout << "Data operacji: " << expenses[i].getUserDate() << endl;
        cout << "Tytul operacji: " << expenses[i].getItem() << endl;
        cout << "Kwota: " << expenses[i].getAmount() << endl << endl;

    }

}

void BudgetManager :: displayOperation(size_t index, vector <Operation> operations) {
    cout << "Id operacji: " << operations[index].getId() << endl;
    cout << "Data operacji: " << operations[index].getUserDate() << endl;
    cout << "Tytul operacji: " << operations[index].getItem() << endl;
    cout << "Kwota: " << operations[index].getAmount() << endl << endl;
}

