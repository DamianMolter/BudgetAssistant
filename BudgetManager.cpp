#include "BudgetManager.h"

void BudgetManager :: addOperation(string fileName){

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Operation operation;
    operation = giveNewOperationData(LOGGED_USER_ID);
    incomes.push_back(operation);
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

    cout << "Podaj date: ";
    input = Utils :: loadLine();
    while(!DateMethods :: isDateCorrect(input)){
        cout << "Data jest nieprawidlowa! Podaj ponownie date!" << endl;
        input = Utils :: loadLine();
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

void BudgetManager :: displayAllIncomes(){

    for(size_t i = 0; i < incomes.size(); i++){
        cout << "Id operacji: " << incomes[i].getId() << " Data operacji: " << incomes[i].getDate() << endl;
        cout << "Tytul operacji: " << incomes[i].getItem() << " Kwota: " << incomes[i].getAmount() << endl << endl;

    }

}

