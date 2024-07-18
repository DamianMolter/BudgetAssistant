#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <string>
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

class Operation{
public:
    int userId;
    string date;
    string title;
    float amount;

    Operation(int userId = 1, string date = "2022-10-22", string title = "Operacja", float amount = 9.99){
    this -> userId = userId;
    this -> date = date;
    this -> title = title;
    this -> amount = amount;
    }
};

int main() {

    Operation operation;
    CMarkup incomeFile;
    bool fileExists = incomeFile.Load("incomes.xml");
    if(!fileExists){

        incomeFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        incomeFile.AddElem("Incomes");

    }

    //incomeFile.ResetPos();
    incomeFile.FindElem();
    incomeFile.IntoElem();
    incomeFile.AddElem("Income");
    incomeFile.IntoElem();
    incomeFile.AddElem("userId", operation.userId);
    incomeFile.AddElem("date", operation.date);
    incomeFile.AddElem("title", operation.title);
    incomeFile.AddElem("amount", to_string(operation.amount));
    incomeFile.Save("incomes.xml");

    incomeFile.ResetPos();
    incomeFile.FindElem();
    incomeFile.IntoElem();
    incomeFile.FindElem();
    incomeFile.IntoElem();
    incomeFile.FindElem("date");
    string date = incomeFile.GetData();
    incomeFile.FindElem("amount");
    float amount = stof(incomeFile.GetData());
    struct tm dataStructure;

    dataStructure.tm_year = stoi(date.substr(0,4));
    dataStructure.tm_mon = stoi(date.substr(5,2));
    dataStructure.tm_mday = stoi(date.substr(8,2));

    cout << dataStructure.tm_year << "-" << dataStructure.tm_mon << "-" << dataStructure.tm_mday << endl;
    cout << amount << endl;


}
