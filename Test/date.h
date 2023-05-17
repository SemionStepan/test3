#ifndef DATE_H
#define DATE_H

class Date
{
private:
    const int DefaultDateDay = 1;
    const int DefaultDateMonth = 1;
    const int DefaultDateYear = 1970;
    const int DaysInYearWithoutFeb = 337;

    int d = DefaultDateDay;
    int m = DefaultDateMonth;
    int y = DefaultDateYear;

    // Дальше реализуем вспомогательные функции-члены.
    // Нам нужно будет понимать високосный ли перед нами год, корректную ли дату ввели:
    int getDaysInFeb(int year) const;

    int getDaysInMonth(int month, int year) const;

    inline int getDaysInYear(int year) const
    {
        return DaysInYearWithoutFeb + getDaysInFeb(year);
    }

    inline bool isCorrectDate() const
    {
        return getMonth() <= 12 && getMonth() >= 1 && getDay() <= getDaysInMonth(getMonth(), getYear()) && getDay() > 0;
    }

    // Помимо прочего будет полезно уметь переводить текущую дату в число — количество дней от 01.01.1970 и обратно.
    int daysPassedToMonth(int month, int year) const;

    int getDays() const;

    void setFromDays(int inp_days);

    // Когда подготовительная часть закончена, реализуем публичный интерфейс:
public:
    Date(int day, int month, int year);

    inline int getDay() const
    {
        return d;
    }

    inline int getMonth() const
    {
        return m;
    }

    inline int getYear() const
    {
        return y;
    }

    Date operator+ (int k) const;
    Date operator- (int k) const;
    int operator- (const Date& other) const;
};

#endif // DATE_H
