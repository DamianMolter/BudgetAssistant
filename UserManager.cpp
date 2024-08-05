#include "UserManager.h"

void UserManager :: registerUser() {
    User user;
    user = giveNewUserData();
    users.push_back(user);
    userFile.addUserToFile(user);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

bool UserManager :: userNameExists(string userName) {

    for(size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserName() == userName) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        } else {
            i++;
        }
    }
    return false;
}

User UserManager :: giveNewUserData() {
    string userName, password, name, surname;
    User user;
    user.setUserId(getNewUserId());

    do {
        cout << endl << "Podaj login: ";
        userName = Utils :: loadLine();
        user.setUserName(userName);
    } while (userNameExists(user.getUserName()) == true);

    cout << "Podaj haslo: ";
    password = Utils :: loadLine();
    user.setPassword(password);

    cout << "Podaj imie: ";
    name = Utils :: loadLine();
    user.setName(name);

    cout << "Podaj nazwisko: ";
    surname = Utils :: loadLine();
    user.setSurname(surname);

    return user;
}

int UserManager :: getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager :: displayAllUsers() {
    for (size_t i = 0; i < users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl << endl;
    }
}

int UserManager :: loginUser(){
    string userName = "", password = "";

    cout << endl << "Podaj login: ";
    userName = Utils:: loadLine();

    for(size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserName() == userName) {
            for (int attemptsRemained = 3; attemptsRemained > 0; attemptsRemained--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsRemained << ": ";
                password = Utils :: loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = users[i].getUserId();
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;

}

bool UserManager :: isUserLogged() {
    if(loggedUserId > 0) {
        return true;
    } else {
        return false;
    }
}

void UserManager :: displayGreetings(){

    string userIdentity = userFile.getLoggedUserIdentity(loggedUserId);
    cout << "Witaj " << userIdentity << "!" << endl;

}

void UserManager :: changePassword(){
    string newPassword;
    cout << "Podaj nowe haslo: ";
    newPassword = Utils :: loadLine();
    cout << "Haslo zostalo pomyslnie zmienione." <<  endl;
    system("pause");
    for(size_t i = 0; i < users.size(); i++){
        if(loggedUserId == users[i].getUserId()){
            users[i].setPassword(newPassword);
            break;
        }
    }
    userFile.saveChangedPassword(loggedUserId,newPassword);
}

void UserManager :: userLogout(){
    loggedUserId = 0;
}
