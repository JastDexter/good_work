#ifndef GOOD_WORK_DATE_H
#define GOOD_WORK_DATE_H

#include <ctime>
#include <stdexcept>
#include <string>
#include "../list/abstractions/Binary.h"

class Date : public Binary{
private:
    int year;
    int month;
    int day;

    bool checkDay(int new_day);

    bool checkMonth(int new_month) const;

    bool checkYear(int new_year) const;

public:
    const int MAX_DAYS[12] = {
            31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
    };
    const int MAX_MONTHS = 12;

    Date(int year, int month, int day);

    Date();

    int getYear() const;

    void setYear(int new_year);

    int getMonth() const;

    void setMonth(int new_month);

    int getDay() const;

    void setDay(int new_day);

    void save_binary(std::ofstream &out) override;

    void load_binary(std::ifstream &in) override;

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;
};


#endif
