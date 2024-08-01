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

char Utils :: loadCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
