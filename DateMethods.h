#pragma once
#include <iostream>
#include <string>

using namespace std;

class DateMethods{
    static int calculateMonthLength(int year, int month);
public:
    static bool isDateCorrect(string date);
    static int convertDateToNumericForm(string date);



};
