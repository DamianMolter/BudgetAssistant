#pragma once
#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;

class DateMethods{
    static int calculateMonthLength(int year, int month);
    static bool isDateFormatCorrect(string date);
public:
    static bool isDateCorrect(string date);
    static int convertDateToNumericForm(string date);
};
