#include <iostream>

#include "date.h"

using namespace std;

int main()
{
    Date date(17, 5, 2023);

    int today = date.getDay();
    int tomorrow = date.getDay() + 1;
    int summ = tomorrow + today;

    cout << summ << endl;

    int notSumm = tomorrow - today;

    cout << notSumm << endl;


    return 0;
}
