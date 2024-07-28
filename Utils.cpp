#include "Utils.h"

string Utils :: loadLine(){
    string input;
    getline(cin, input);
    return input;
};

string Utils :: changeComaToDot(string input){
    size_t comaPosition = input.find(',');

    if(comaPosition != string::npos){
        input.erase(comaPosition, 1);
        input.insert(comaPosition, 1, '.');
    }
    return input;
}
