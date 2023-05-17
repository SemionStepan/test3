#include <iostream>

#include "date.h"

Date::Date(int day, int month, int year)
    : d{day}, m{month}, y{year} {
    if (!IsCorrectDate()) {
        d = DefaultDateDay;
        m = DEFAULT_DATE_MONTH;
        y = DEFAULT_DATE_YEAR;
    }
}

Date Date::operator +(int k) const {
    Date result(*this);
    result.SetFromDays(result.GetDays() + k);
    return result;
}

int Date::operator -(const Date &other) const {
    return GetDays() - other.GetDays();
}

Date Date::operator -(int k) const {
    Date result(*this);
    result.SetFromDays(result.GetDays() - k);
    return result;
}

int Date::getDaysInFeb(int year) const {
    if ((!(year % 4) && (year % 100)) || !(year % 400)) {
        return 29;
    }
    return 28;
}

int Date::GetDaysInMonth(int month, int year) const {
    switch (month) {
    case 2:
        return getDaysInFeb(year);
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    default:
        return 30;
    }
}

int Date::DaysPassedToMonth(int month, int year) const {
    int days = 0;
    for (int i = 1; i < month; ++i) {
        days += GetDaysInMonth(i, year);
    }
    return days;
}

int Date::GetDays() const {
    int days = 0;
    for (int i = DEFAULT_DATE_YEAR; i < GetYear(); ++i) {
        days += GetDaysInYear(i);
    }
    return days + DaysPassedToMonth(GetMonth(), GetYear()) + GetDay();
}

void Date::SetFromDays(int inp_days) {
    m = DEFAULT_DATE_MONTH;
    y = DEFAULT_DATE_YEAR;

    while (inp_days > GetDaysInYear(GetYear())) {  // сначала определяем год
        inp_days -= GetDaysInYear(GetYear());
        ++y;
    }

    while (inp_days > DaysPassedToMonth(GetMonth() + 1, GetYear())) {  // определяем месяц
        ++m;
    }

    d = inp_days - DaysPassedToMonth(GetMonth(), GetYear());  // остаток в дни
}


