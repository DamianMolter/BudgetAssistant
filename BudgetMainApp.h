#pragma once
#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;
public:
    BudgetMainApp(string userFileName): userManager(userFileName){};

    void registerUser();
    void displayAllUsers();


};
