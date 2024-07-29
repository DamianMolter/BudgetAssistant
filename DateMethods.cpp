#include "DateMethods.h"

bool DateMethods :: isDateCorrect(string date) {

    bool isDateCorect;
    size_t firstDashPosition = date.find_first_of('-');
    size_t secondDashPosition = date.find_last_of('-');
    int year = stoi(date.substr(0, firstDashPosition));
    int month = stoi(date.substr(firstDashPosition + 1, secondDashPosition - firstDashPosition - 1));
    int day = stoi(date.substr(secondDashPosition + 1));

    int monthLength = calculateMonthLength(year, month);


    if(firstDashPosition == 4 && year >= 2000 && month >= 1 && month <= 12 && day >= 0 && day <= monthLength) {
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

int DateMethods :: convertDateToNumericForm(string date){

    int dateNumericForm;
    size_t firstDashPosition = date.find_first_of('-');
    size_t secondDashPosition = date.find_last_of('-');
    int year = stoi(date.substr(0, firstDashPosition));
    int month = stoi(date.substr(firstDashPosition + 1, secondDashPosition - firstDashPosition - 1));
    int day = stoi(date.substr(secondDashPosition + 1));

    dateNumericForm = (year * 10000) + (month * 100) + day;
    return dateNumericForm;

}
