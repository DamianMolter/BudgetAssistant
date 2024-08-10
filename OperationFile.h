#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "File.h"
#include "Operation.h"
#include "Markup.h"
#include "DateMethods.h"

using namespace std;

class OperationFile : public File{

public:
    OperationFile(){};
    vector <Operation> loadOperations(string fileName, int loggedUserId);
    void addOperationToFile(Operation operation, string fileName);

};
