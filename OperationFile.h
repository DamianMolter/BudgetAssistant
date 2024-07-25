#pragma once
#include <iostream>
#include <vector>
#include "File.h"
#include "Operation.h"
#include "Markup.h"

using namespace std;

class OperationFile : public File{

public:
    vector <Operation> loadOperations(string fileName);

};
