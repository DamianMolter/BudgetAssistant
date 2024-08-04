#pragma once
#include <iostream>

using namespace std;

class Operation{
    int id;
    int userId;
    int date;
    string userDate;
    string item;
    double amount;
public:
    Operation(){
        id = 0;
    }
    int getId();
    int getUserId();
    int getDate();
    string getUserDate();
    string getItem();
    double getAmount();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setUserDate(string newUserDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};
