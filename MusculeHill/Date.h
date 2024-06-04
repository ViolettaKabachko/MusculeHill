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
        return (day > 9 ? std::to_string(day) : "0" + std::to_string(day)) + "." +
            (month > 9 ? std::to_string(month) : "0" + std::to_string(month)) + "." +
            std::to_string(year) + " " + 
            (hour > 9 ? std::to_string(hour) : "0" + std::to_string(hour)) + 
            ":" + (minute > 9 ? std::to_string(minute) : "0" + std::to_string(minute));
    }

    bool operator==(const Date& other) {
        return this->day == other.day && this->month == other.month && this->hour == other.hour && this->year == year && this->minute == other.minute;
    }
};