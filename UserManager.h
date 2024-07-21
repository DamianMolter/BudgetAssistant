#pragma once
#include <iostream>
#include <vector>
#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager{

    vector <User> users;
    UserFile userFile;
    User giveNewUserData();
    bool userNameExists(string userName);
    int getNewUserId();
    vector <User> loadUsersFromFile();

public:
    UserManager(string userFileName) : userFile(userFileName){
        users = userFile.loadUsersFromFile(userFileName);
    };
    void registerUser();
    void displayAllUsers();

};
