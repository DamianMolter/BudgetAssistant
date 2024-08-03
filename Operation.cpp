#include "Operation.h"

int Operation :: getId(){
    return id;
}
int Operation :: getUserId(){
    return userId;
}
int Operation :: getDate(){
    return date;
}
string Operation :: getUserDate(){
    return userDate;
}
string Operation :: getItem(){
    return item;
}
float Operation :: getAmount(){
    return amount;
}

void Operation :: setId(int newId){
    this -> id = newId;
}
void Operation :: setUserId(int newUserId){
    this -> userId = newUserId;
}
void Operation :: setDate(int newDate){
    this -> date = newDate;
}
void Operation :: setUserDate(string newUserDate){
    this -> userDate = newUserDate;
}
void Operation :: setItem(string newItem){
    this -> item = newItem;
}
void Operation :: setAmount(float newAmount){
    this -> amount = newAmount;
}
