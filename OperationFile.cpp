#include "OperationFile.h"

vector <Operation> OperationFile :: loadOperations(string fileName, int loggedUserId) {

    Operation operation;
    vector <Operation> operations;

    CMarkup operationFile;

    bool success = operationFile.Load(fileName);
    if(success) {
        operationFile.FindElem();
        operationFile.IntoElem();
        while(operationFile.FindElem("Operation")){
            operationFile.IntoElem();
            operationFile.FindElem("UserId");
            if(stoi(operationFile.GetData()) == loggedUserId){
                operation.setUserId(stoi(operationFile.GetData()));
            } else {
                operationFile.OutOfElem();
                continue;
            }
            operationFile.FindElem("Id");
            operation.setId(stoi(operationFile.GetData()));
            operationFile.FindElem("Date");
            operation.setDate(stoi(operationFile.GetData()));
            operationFile.FindElem("UserDate");
            operation.setUserDate(operationFile.GetData());
            operationFile.FindElem("Item");
            operation.setItem(operationFile.GetData());
            operationFile.FindElem("Amount");
            operation.setAmount(stod(operationFile.GetData()));
            operationFile.OutOfElem();
            operations.push_back(operation);
        }


    }

    return operations;

}

void OperationFile :: addOperationToFile(Operation operation, string fileName) {

    CMarkup operationFile;

    bool fileExists = operationFile.Load(fileName);
    if(!fileExists) {

        operationFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        operationFile.AddElem("Operations");

    }
    operationFile.FindElem();
    operationFile.IntoElem();
    operationFile.AddElem("Operation");
    operationFile.AddChildElem("UserId", operation.getUserId());
    operationFile.AddChildElem("Id", operation.getId());
    operationFile.AddChildElem("Date", operation.getDate());
    operationFile.AddChildElem("UserDate", operation.getUserDate());
    operationFile.AddChildElem("Item", operation.getItem());
    operationFile.AddChildElem("Amount", operation.getAmount());
    operationFile.OutOfElem();
    operationFile.Save(fileName);
}
