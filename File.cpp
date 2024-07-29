#include "File.h"

string File :: getFileName() {
    return FILE_NAME;
}

int File :: getLastIdFromFile(string fileName) {
    int lastId = 0;

    CMarkup file;

    if(file.Load(fileName)) {
        file.FindElem();
        file.IntoElem();
        while(file.FindElem("Operation")) {
            file.IntoElem();
            file.FindElem("Id");
            lastId = stoi(file.GetData());
            file.OutOfElem();
        }
    }
    return lastId;

}

int File :: getLastId(string incomeFileName, string expenseFileName) {

    int incomeLastId = 0;
    int expenseLastId = 0;

    incomeLastId = getLastIdFromFile(incomeFileName);
    expenseLastId = getLastIdFromFile(expenseFileName);

    if(incomeLastId > expenseLastId) {
        return incomeLastId;
    } else {
        return expenseLastId;
    }
}
