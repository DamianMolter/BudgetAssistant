#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager{

    int loggedUserId;
    vector <User> users;
    UserFile userFile;
    User giveNewUserData();
    bool userNameExists(string userName);
    int getNewUserId();
    vector <User> loadUsersFromFile();


public:
    UserManager(string userFileName) : userFile(userFileName){
        loggedUserId = 0;
        users = userFile.loadUsersFromFile(userFileName);
    };
    void registerUser();
    int loginUser();
    bool isUserLogged();
    void displayGreetings();
    void displayAllUsers(); // test
    void changePassword();
    void userLogout();

};
