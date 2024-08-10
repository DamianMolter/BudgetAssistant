#include "BudgetManager.h"

void BudgetManager :: addIncome(string fileName) {

    system("cls");
    cout << ">>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Operation operation = giveNewOperationData(LOGGED_USER_ID, lastIncomeId);
    incomes.push_back(operation);
    incomeFile.addOperationToFile(operation, fileName);
    lastIncomeId++;
}

void BudgetManager :: addExpense(string fileName) {

    system("cls");
    cout << ">>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Operation operation = giveNewOperationData(LOGGED_USER_ID, lastExpenseId);
    expenses.push_back(operation);
    expenseFile.addOperationToFile(operation, fileName);
    lastExpenseId++;
}

void BudgetManager :: showSummary(int beginOfMonth, int endOfMonth){

    double incomeSum = 0.00;
    double expenseSum = 0.00;

    cout << "==============================" << endl;
    cout << "WYKAZ PRZYCHODOW:" << endl;
    for (size_t i = 0; i < incomes.size(); i++) {
        if(incomes[i].getDate() > beginOfMonth && incomes[i].getDate() < endOfMonth) {
            displayOperation(i, incomes);
            incomeSum += incomes[i].getAmount();
        }
    }
    cout << "==============================" << endl;
    cout << "WYKAZ WYDATKOW:" << endl;
    for (size_t j = 0; j < expenses.size(); j++) {
        if(expenses[j].getDate() > beginOfMonth && expenses[j].getDate() < endOfMonth){
            displayOperation(j, expenses);
            expenseSum += expenses[j].getAmount();
        }
    }


    cout << "Suma przychodow to: " << fixed << setprecision(2) << incomeSum << endl;
    cout << "Suma wydatkow to: " << expenseSum << endl;
    cout << "Bilans za wybrany okres to: " << incomeSum - expenseSum << endl;
    system("pause");
}

void BudgetManager :: showRecentMonthSummary() {

    int beginOfRecentMonth = DateMethods :: getRecentMonthBegin();
    int endOfRecentMonth = beginOfRecentMonth + DateMethods :: calculateRecentMonthLength() + 1;

    cout << "==============================" << endl;
    cout << "BILANS ZA BIEZACY MIESIAC:" << endl << endl;

    showSummary(beginOfRecentMonth, endOfRecentMonth);
}

void BudgetManager :: showLastMonthSummary(){

    int beginOfLastMonth = DateMethods :: getLastMonthBegin();
    int endOfLastMonth = beginOfLastMonth + DateMethods :: calculateLastMonthLength()+ 1;

    cout << "==============================" << endl;
    cout << "BILANS ZA POPRZEDNI MIESIAC:" << endl << endl;

    showSummary(beginOfLastMonth, endOfLastMonth);

}

void BudgetManager :: showCustomSummary(){

    string input;
    cout << "Wprowadz date poczatkowa: " << endl;
    input = insertDate();
    int customPeriodBegin = DateMethods :: convertDateToNumericForm(input);

    cout << "Wprowadz date koncowa: " << endl;
    input = insertDate();
    int customPeriodEnd = DateMethods :: convertDateToNumericForm(input);

    showSummary( customPeriodBegin, customPeriodEnd);
}

string BudgetManager :: insertDate(){

    string input;
    cout << "Podaj date: ";
        input = Utils :: loadLine();
        while(!DateMethods :: isDateCorrect(input)) {
            cout << "Data jest nieprawidlowa! Podaj ponownie date!" << endl;
            input = Utils :: loadLine();
        }
    return input;
}

Operation BudgetManager :: giveNewOperationData(int loggedUserId, int lastOperationId) {
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
        input = insertDate();
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
    operation.setAmount(stod(input));

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

