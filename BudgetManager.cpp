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
    operation.setAmount(input);

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

