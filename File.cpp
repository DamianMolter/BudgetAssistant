#include "File.h"

string File :: getFileName(){
    return FILE_NAME;
}

int File :: getLastId(string fileName){

    CMarkup file;
    file.Load(fileName);
    file.FindElem();
    file.IntoElem();
    while(file.FindElem("Operation")){
        lastId++;
    }

    return lastId;
}
