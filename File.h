#pragma once
#include <iostream>
#include "Markup.h"

using namespace std;

class File{

    const string FILE_NAME;
    int lastId;

public:
    File(){
        lastId = 0;
    }
    string getFileName();
    int getLastId(string fileName);




};
