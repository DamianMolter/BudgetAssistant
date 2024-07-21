#pragma once
#include <iostream>

using namespace std;


class User {
    int userId;
    string userName, password, name, surname;
public:
    int getUserId();
    string getUserName();
    string getPassword();
    string getName();
    string getSurname();
    void setUserId(int newId);
    void setUserName(string newUserName);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);


};
