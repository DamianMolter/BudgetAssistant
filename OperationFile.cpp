#include "OperationFile.h"

vector <Operation> OperationFile :: loadOperations(string fileName){

    Operation operation;
    vector <Operation> operations;

    CMarkup incomeFile;

    incomeFile.Load(fileName);
    incomeFile.FindElem();
    incomeFile.IntoElem();
    bool incomeFound = incomeFile.FindElem("Operation");
    while(incomeFound){
        incomeFile.IntoElem();
        incomeFile.FindElem("Id");
        operation.setId(stoi(incomeFile.GetData()));
        incomeFile.FindElem("UserId");
        operation.setId(stoi(incomeFile.GetData()));
        incomeFile.FindElem("Date");
        operation.setId(stoi(incomeFile.GetData()));
        incomeFile.FindElem("Item");
        operation.setId(stoi(incomeFile.GetData()));
        incomeFile.FindElem("Amount");
        operation.setId(stof(incomeFile.GetData()));
        incomeFile.OutOfElem();
    }
    return operations;

}
