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
