#pragma once
#include <iostream>

using namespace std;

class Operation{
    int id;
    int userId;
    int date;
    string userDate;
    string item;
    string amount;
public:
    Operation(){
        id = 0;
    }
    int getId();
    int getUserId();
    int getDate();
    string getUserDate();
    string getItem();
    string getAmount();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setUserDate(string newUserDate);
    void setItem(string newItem);
    void setAmount(string newAmount);
};
