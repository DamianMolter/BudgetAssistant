#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include "Utils.h"

using namespace std;

class DateMethods{
    static int calculateMonthLength(int year, int month);
    static bool isDateFormatCorrect(string date);
    static void addZeroToOneDigitMonthOrDay(string &input);
public:
    static bool isDateCorrect(string date);
    static int convertDateToNumericForm(string date);
    static bool wantedTodayDate();
    static string loadTodayDate();
};
