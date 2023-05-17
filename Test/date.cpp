#include <iostream>

#include "date.h"

Date::Date(int day, int month, int year)
    : d{day}, m{month}, y{year}
{
    if (!isCorrectDate())
    {
        d = DefaultDateDay;
        m = DefaultDateMonth;
        y = DefaultDateYear;
    }
}

Date Date::operator +(int k) const
{
    Date result(*this);
    result.setFromDays(result.getDays() + k);
    return result;
}

int Date::operator -(const Date &other) const
{
    return getDays() - other.getDays();
}

Date Date::operator -(int k) const
{
    Date result(*this);
    result.setFromDays(result.getDays() - k);
    return result;
}

int Date::getDaysInFeb(int year) const
{
    if ((!(year % 4) && (year % 100)) || !(year % 400))
    {
        return 29;
    }
    return 28;
}

int Date::getDaysInMonth(int month, int year) const
{
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return getDaysInFeb(year);
    default:
        return 30;
    }
}

int Date::daysPassedToMonth(int month, int year) const
{
    int days = 0;
    for (int i = 1; i < month; ++i) {
        days += getDaysInMonth(i, year);
    }
    return days;
}

int Date::getDays() const
{
    int days = 0;
    for (int i = DefaultDateYear; i < getYear(); ++i) {
        days += getDaysInYear(i);
    }
    return days + daysPassedToMonth(getMonth(), getYear()) + getDay();
}

void Date::setFromDays(int inp_days) {
    m = DefaultDateMonth;
    y = DefaultDateYear;

    while (inp_days > getDaysInYear(getYear()))
    {  // сначала определяем год
        inp_days -= getDaysInYear(getYear());
        ++y;
    }

    while (inp_days > daysPassedToMonth(getMonth() + 1, getYear()))
    {  // определяем месяц
        ++m;
    }

    d = inp_days - daysPassedToMonth(getMonth(), getYear());  // остаток в дни
}


