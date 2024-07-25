#include "BudgetManager.h"



void BudgetManager :: addIncome(){

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Operation operation;
    operation = giveNewOperationData(LOGGED_USER_ID);
    incomes.push_back(operation);
    //tu skonczylem i tutaj wznowie dzielo
    //recipientFile.addRecipientToFile(operation);
    lastOperationId++;
}

Operation BudgetManager :: giveNewOperationData(int loggedUserId) {
    Operation operation;
    string input;
    int date;
    string item;
    float amount;
    operation.setId(lastOperationId + 1);
    operation.setUserId(LOGGED_USER_ID);

    cout << "Podaj date: ";
    input = Utils :: loadLine();
    while(!DateMethods :: isDateCorrect(input)){
        cout << "Data jest nieprawidlowa! Podaj ponownie date!" << endl;
        input = Utils :: loadLine();
    }
    date = DateMethods :: convertDateToNumericForm(input);
    operation.setDate(date);

    cout << "Podaj tytul: ";
    input = Utils :: loadLine();
    operation.setItem(input);

    cout << "Podaj kwote: ";
    input = Utils:: loadLine();
    amount = Utils :: convertFromStringToMoneyAmount(input);
    operation.setAmount(amount);

    return operation;
}

