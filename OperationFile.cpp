#include "OperationFile.h"

vector <Operation> OperationFile :: loadOperations(string fileName, int loggedUserId) {

    Operation operation;
    vector <Operation> operations;

    CMarkup operationFile;

    bool success = operationFile.Load(fileName);
    if(success) {
        operationFile.FindElem();
        operationFile.IntoElem();
        while(operationFile.FindElem("Operation")) {
            operationFile.FindChildElem("UserId");
            int checkedUserId = stoi(operationFile.GetChildData());
            if( checkedUserId == loggedUserId) {
                operation.setUserId(checkedUserId);
                operationFile.ResetChildPos();
                operationFile.FindChildElem("Id");
                operation.setId(stoi(operationFile.GetChildData()));
                operationFile.FindChildElem("UserDate");
                operation.setUserDate(operationFile.GetChildData());
                operation.setDate(DateMethods ::convertDateToNumericForm(operation.getUserDate()));
                operationFile.FindChildElem("Item");
                operation.setItem(operationFile.GetChildData());
                operationFile.FindChildElem("Amount");
                operation.setAmount(stod(operationFile.GetChildData()));
                operations.push_back(operation);
            }
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
    operationFile.AddChildElem("Id", operation.getId());
    operationFile.AddChildElem("UserId", operation.getUserId());
    operationFile.AddChildElem("UserDate", operation.getUserDate());
    operationFile.AddChildElem("Item", operation.getItem());
    operationFile.AddChildElem("Amount", to_string(operation.getAmount()));
    operationFile.OutOfElem();
    operationFile.Save(fileName);
}
