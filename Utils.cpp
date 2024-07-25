#include "Utils.h"

string Utils :: loadLine(){
    string input;
    getline(cin, input);
    return input;
};

float Utils :: convertFromStringToMoneyAmount(string input){
    size_t comaPosition = input.find(',');

    if(comaPosition != string::npos){
        input.erase(comaPosition);
        input.insert(comaPosition, 1, '.');
    }

    float amount = stof(input);
    return round(amount * 100)/100;
}
