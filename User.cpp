#include "User.h"

int User :: getUserId(){
    return userId;
}

string User :: getUserName(){
    return userName;
}

string User :: getPassword(){
    return password;
}

string User :: getName(){
    return name;
}

string User :: getSurname(){
    return surname;
}

void User :: setUserId(int newId){
    userId = newId;
}
void User :: setUserName(string newUserName){
    userName = newUserName;
}
void User :: setPassword(string newPassword){
    password = newPassword;
}
void User :: setName(string newName){
    name = newName;
}
void User :: setSurname(string newSurname){
    surname = newSurname;
}
