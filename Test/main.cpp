#include <iostream>

#include "date.h"

using namespace std;

int main()
{
    Date date(1, 3, 2022);

    int day = date.GetDay();

    cout << day << endl;

    return 0;
}
