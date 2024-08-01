#include "DateMethods.h"

bool DateMethods :: isDateCorrect(string date) {

    do {
        if(!isDateFormatCorrect(date)) {
            cout << "Podales nieprawidlowa date. Sproboj ponownie!" << endl;
            date = Utils :: loadLine();
        }

    } while(!isDateFormatCorrect(date));

    size_t firstDashPosition = date.find_first_of('-');
    size_t secondDashPosition = date.find_last_of('-');
    string year = date.substr(0, firstDashPosition);
    string month = date.substr(firstDashPosition + 1, secondDashPosition - firstDashPosition - 1);
    string day = date.substr(secondDashPosition + 1);

    bool isDateCorect;

    int yearInt = stoi(year);
    int monthInt = stoi(month);
    int dayInt = stoi(day);


    int monthLength = calculateMonthLength(yearInt, monthInt);


    if(firstDashPosition == 4 && yearInt >= 2000 && monthInt >= 1 && monthInt <= 12 && dayInt >= 0 && dayInt <= monthLength) {
        isDateCorect = true;
    } else {
        isDateCorect = false;
    }
    return isDateCorect;
}

int DateMethods :: calculateMonthLength(int year, int month) {
    int monthLength = 0;

    switch(month) {
    case 2:
        if(year % 4 == 0) {
            monthLength = 29;
        } else {
            monthLength = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        monthLength = 30;
        break;
    default:
        monthLength = 31;
        break;
    }

    return monthLength;
}

int DateMethods :: convertDateToNumericForm(string date) {

    int dateNumericForm;
    size_t firstDashPosition = date.find_first_of('-');
    size_t secondDashPosition = date.find_last_of('-');
    int year = stoi(date.substr(0, firstDashPosition));
    int month = stoi(date.substr(firstDashPosition + 1, secondDashPosition - firstDashPosition - 1));
    int day = stoi(date.substr(secondDashPosition + 1));

    dateNumericForm = (year * 10000) + (month * 100) + day;
    return dateNumericForm;

}

bool DateMethods :: isDateFormatCorrect(string date) {

    if((date[5] >= 48 && date[5] <= 49) && (date[8] >= 48 && date[8] <= 51)) {
        return true;
    } else {
        return false;
    }

}
