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
