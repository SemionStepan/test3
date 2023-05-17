#ifndef DATE_H
#define DATE_H

class Date {
private:
    const int DefaultDateDay = 1;
    const int DEFAULT_DATE_MONTH = 1;
    const int DEFAULT_DATE_YEAR = 1970;
    const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

    int d = DefaultDateDay;
    int m = DEFAULT_DATE_MONTH;
    int y = DEFAULT_DATE_YEAR;

    // Дальше реализуем вспомогательные функции-члены.
    // Нам нужно будет понимать високосный ли перед нами год, корректную ли дату ввели:
    int getDaysInFeb(int year) const;

    int GetDaysInMonth(int month, int year) const;

    inline int GetDaysInYear(int year) const {
        return DAYS_IN_YEAR_WITHOUT_FEB + getDaysInFeb(year);
    }

    inline bool IsCorrectDate() const {
        return GetMonth() <= 12 && GetMonth() >= 1 && GetDay() <= GetDaysInMonth(GetMonth(), GetYear()) && GetDay() > 0;
    }

    // Помимо прочего будет полезно уметь переводить текущую дату в число — количество дней от 01.01.1970 и обратно.
    int DaysPassedToMonth(int month, int year) const;

    int GetDays() const;

    void SetFromDays(int inp_days);

    // Когда подготовительная часть закончена, реализуем публичный интерфейс:
public:
    Date(int day, int month, int year);

    inline int GetDay() const {
        return d;
    }

    inline int GetMonth() const {
        return m;
    }

    inline int GetYear() const {
        return y;
    }

    Date operator+ (int k) const;
    Date operator- (int k) const;
    int operator- (const Date& other) const;
};

#endif // DATE_H
