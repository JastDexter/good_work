#include "Date.h"

Date::Date(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    year = ltm->tm_year;
    month = ltm->tm_mon;
    day = ltm->tm_mday;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int new_year) {
    if (checkYear(new_year))
        Date::year = new_year;
    else
        throw std::out_of_range("Year " + std::to_string(new_year) + " out of range.");
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int new_month) {
    if (checkMonth(new_month))
        Date::month = new_month;
    else
        throw std::out_of_range("Month " + std::to_string(new_month) + " out of range.");
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int new_day) {
    if (checkDay(new_day))
        Date::day = new_day;
    else
        throw std::out_of_range("Day " + std::to_string(new_day) + " out of range.");
}

bool Date::checkDay(int new_day) {
    return new_day > 0 && (new_day <= ((month == 2 && year % 4) ? MAX_DAYS[month-1] + 1 : MAX_DAYS[month-1]));
}

bool Date::checkMonth(int new_month) const {
    return new_month <= MAX_MONTHS && new_month > 0;
}

bool Date::checkYear(int new_year) const {
    return new_year > 0;
}

bool Date::operator==(const Date &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

bool Date::operator<(const Date &rhs) const {
    return year < rhs.year
           || (year == rhs.year && month < rhs.month)
           || (year == rhs.year && month == rhs.month && day < rhs.day);
}

bool Date::operator>(const Date &rhs) const {
    return year > rhs.year
           || (year == rhs.year && month > rhs.month)
           || (year == rhs.year && month == rhs.month && day > rhs.day);
}

bool Date::operator<=(const Date &rhs) const {
    return year <= rhs.year
           || (year == rhs.year && month <= rhs.month)
           || (year == rhs.year && month == rhs.month && day <= rhs.day);
}

bool Date::operator>=(const Date &rhs) const {
    return year >= rhs.year
           || (year == rhs.year && month >= rhs.month)
           || (year == rhs.year && month == rhs.month && day >= rhs.day);
}

void Date::save_binary(std::ofstream &out) {
    out.write((char *) &year, sizeof(year));
    out.write((char *) &month, sizeof(month));
    out.write((char *) &day, sizeof(day));
}

void Date::load_binary(std::ifstream &in) {
    in.read((char *) &year, sizeof(year));
    in.read((char *) &month, sizeof(month));
    in.read((char *) &day, sizeof(day));
}
