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
    int loggedUserId;

public:
    UserManager(string userFileName) : userFile(userFileName){
        loggedUserId = 0;
        users = userFile.loadUsersFromFile(userFileName);
    };
    void registerUser();
    int loginUser();
    bool isUserLogged();
    void displayAllUsers();

};
