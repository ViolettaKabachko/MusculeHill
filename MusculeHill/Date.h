#pragma once
#include <string>

class Date {
public :
    int day;
    int month;
    int year;
    int hour;
    int minute;

    Date() {
        day = 0;
        month = 0;
        year = 0;
        hour = 0;
        minute = 0;
    }

    Date(int year, int month, int day, int hour, int minute) : year(year), month(month), day(day), hour(hour), minute(minute) {};

    std::string get_string() {
        return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year) + " " + std::to_string(hour) + ":" + std::to_string(minute);
    }
};