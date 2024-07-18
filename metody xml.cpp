#include <iostream>
#include <string>
#include <vector>
#include "Markup.h"

using namespace std;

class User {
public:
    int userId;
    string userName, name, surname;

    User(int userId = 0, string userName = "jankow", string name = "Jan", string surname = "Kowalski") {

        this->userId = userId;
        this->userName=userName;
        this->name=name;
        this->surname=surname;

    }
};



int main() {

    vector <User> users;
    User user;
    User szymek(3,"chrabaszcz", "Szymon", "Molter");

    /* cout << ada.userId << endl;
     cout << ada.userName << endl;
     cout << ada.name << endl;
     cout << ada.surname << endl;*/


    //tworzenie pliku od zera z nadpisaniem
    /*CMarkup userFile;
    userFile.Load("users.xml");
    userFile.AddElem("UserFile");
    userFile.IntoElem();
    userFile.AddElem("User");
    userFile.AddChildElem("userId", ada.userId);
    userFile.AddChildElem("userName", ada.userName);
    userFile.AddChildElem("name", ada.name);
    userFile.AddChildElem("surname", ada.surname);
    userFile.Save("users.xml");*/

    //ladowanie do wektora
    CMarkup userFile;
    userFile.Load("users.xml");
    userFile.ResetPos();
    userFile.FindElem();
    userFile.IntoElem();
    while(userFile.FindElem("User")) {

        userFile.IntoElem();
        userFile.FindElem("userId");
        user.userId = stoi(userFile.GetData());
        userFile.FindElem("userName");
        user.userName = userFile.GetData();
        userFile.FindElem("name");
        user.name = userFile.GetData();
        userFile.FindElem("surname");
        user.surname = userFile.GetData();
        userFile.OutOfElem();
        users.push_back(user);
    }

    //dodawanie kolejnego rekordu do pliku

    /*CMarkup userFile;
    userFile.Load("users.xml");
    userFile.FindElem();
    userFile.IntoElem();
    userFile.AddElem("User");
    userFile.AddChildElem("userId", szymek.userId);
    userFile.AddChildElem("userName", szymek.userName);
    userFile.AddChildElem("name", szymek.name);
    userFile.AddChildElem("surname", szymek.surname);
    userFile.OutOfElem();
    userFile.Save("users.xml");*/


    for(int i = 0; i < users.size(); i++) {

        cout << users[i].userId << endl;
        cout << users[i].userName << endl;
        cout << users[i].name << endl;
        cout << users[i].surname << endl << endl;

    }

}
