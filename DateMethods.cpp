#include "DateMethods.h"

bool DateMethods :: isDateCorrect(string date) {

    bool isDateCorect;
    if(!isDateFormatCorrect(date)) {
        isDateCorect = false;
        return isDateCorect;
    }

    size_t firstDashPosition = date.find_first_of('-');
    size_t secondDashPosition = date.find_last_of('-');
    string year = date.substr(0, firstDashPosition);
    string month = date.substr(firstDashPosition + 1, secondDashPosition - firstDashPosition - 1);
    string day = date.substr(secondDashPosition + 1);

    int yearInt = stoi(year);
    int monthInt = stoi(month);
    int dayInt = stoi(day);


    int monthLength = calculateMonthLength(yearInt, monthInt);

    time_t timestamp;
    time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    int currentYear = datetime.tm_year + 1900;
    int currentMonth = datetime.tm_mon + 1;

    if(firstDashPosition == 4
            && yearInt >= 2000 && yearInt <= currentYear
            && monthInt >= 1 && monthInt <= currentMonth
            && dayInt >= 1 && dayInt <= monthLength) {
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

    if((date[5] >= 48 && date[5] <= 49) && (date[8] >= 48 && date[8] <= 51) && date.length() == 10) {
        return true;
    } else {
        return false;
    }

}

bool DateMethods :: wantedTodayDate() {
    system("cls");
    char choice;
    cout << "Czy chcesz wprowadzic dzisiejsza date? t/n" << endl;

    do {
        choice = Utils :: loadCharacter();
        switch(choice) {

        case 't':
            return true;
        case 'n':
            return false;
        default:
            cout << "Podaj wlasciwa odpowiedz!" << endl;
            system("pause");

        }
    } while(choice != 't' || choice != 'n');
}

void DateMethods ::  addZeroToOneDigitMonthOrDay(string &input) {
    if(input.length() == 1) {
        input = '0' + input;
    }
}

string DateMethods :: loadTodayDate() {

    time_t timestamp;
    time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    string year = to_string(datetime.tm_year + 1900);
    string month = to_string(datetime.tm_mon + 1);
    string day = to_string(datetime.tm_mday);

    addZeroToOneDigitMonthOrDay(month);
    addZeroToOneDigitMonthOrDay(day);

    string date = year + '-' + month + '-' + day;

    return date;
}

bool DateMethods :: compareDates(Operation operation1, Operation operation2) {
    return operation1.getDate() < operation2.getDate();
}

int DateMethods :: getRecentMonthBegin() {
    time_t timestamp;
    time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    int year = datetime.tm_year + 1900;
    int month = datetime.tm_mon + 1;

    int recentMonthBegin = (year * 10000) + (month * 100);
    return recentMonthBegin;
}

int DateMethods :: calculateRecentMonthLength() {
    time_t timestamp;
    time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    int year = datetime.tm_year + 1900;
    int month = datetime.tm_mon + 1;

    int recentMonthLength = calculateMonthLength(year, month);
    return recentMonthLength;
}


int DateMethods :: getLastMonthBegin() {
    time_t timestamp;
    time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    int year = datetime.tm_year + 1900;
    int month = datetime.tm_mon + 1;

    if(month == 1) {
        year -= 1;
        month = 12;
    } else {
        month -= 1;
    }
    int lastMonthBegin = (year * 10000) + (month * 100);
    return lastMonthBegin;
}

int DateMethods :: calculateLastMonthLength() {
    time_t timestamp;
    time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    int year = datetime.tm_year + 1900;
    int month = datetime.tm_mon + 1;

    if(month == 1) {
        year -= 1;
        month = 12;
    } else {
        month -= 1;
    }

    int lastMonthLength = calculateMonthLength(year, month);
    return lastMonthLength;
}
