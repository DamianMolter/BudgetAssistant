#pragma once
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "File.h"

using namespace std;

class UserFile : public File {


public:
    UserFile(string userFileName){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile(string userFileName);
};
