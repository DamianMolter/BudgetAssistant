#include "UserFile.h"

void UserFile :: addUserToFile(User user){

    CMarkup userFile;
    bool userFileExists = userFile.Load("users.xml");
    if(!userFileExists){
        userFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        userFile.AddElem("Users");
    }
    userFile.FindElem();
    userFile.IntoElem();
    userFile.AddElem("User");
    userFile.AddChildElem("userId", user.getUserId());
    userFile.AddChildElem("userName", user.getUserName());
    userFile.AddChildElem("password", user.getPassword());
    userFile.AddChildElem("name", user.getName());
    userFile.AddChildElem("surname", user.getSurname());
    userFile.Save("users.xml");

};

vector <User> UserFile :: loadUsersFromFile(string userFileName){

    User user;
    vector <User> users;
    CMarkup userFile;
    userFile.Load(userFileName);
    userFile.FindElem();
    userFile.IntoElem(); //into Users

    while(userFile.FindElem("User")){

        userFile.IntoElem();
        userFile.FindElem("userId");
        user.setUserId(stoi(userFile.GetData()));
        userFile.FindElem("userName");
        user.setUserName(userFile.GetData());
        userFile.FindElem("password");
        user.setPassword(userFile.GetData());
        userFile.FindElem("name");
        user.setName(userFile.GetData());
        userFile.FindElem("surname");
        user.setSurname(userFile.GetData());
        userFile.OutOfElem();

        users.push_back(user);
    }

    return users;

};
