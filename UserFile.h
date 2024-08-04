#pragma once
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "File.h"

using namespace std;

class UserFile : public File {
    const string USER_FILE_NAME;

public:
    UserFile(string userFileName) : USER_FILE_NAME(userFileName){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile(string userFileName);
    void saveChangedPassword(int loggedUserId, string newPassword);
};
