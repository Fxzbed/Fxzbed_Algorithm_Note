#include <iostream>

using namespace std;

struct date {
    int year;
    int month;
    int day;

    bool is() const {
        return !(month == 2 || month == 4 || month == 6 || month == 9 || month == 11);
    }

    bool isR() {
        return (year % 4 == 0 || (!(year % 100) && year % 400 == 0));
    }

    void operator ++ (int i) {
        if (is()) {
            if (day < 31) day ++;
            else {
                if (month != 12)
                    month ++;
                else {
                    year ++;
                    month = 1;
                }
                day = 1;
            }
        } else {
            if (month == 2) {
                if (isR()) {
                    if (day != 29) day ++;
                    else {
                        month ++;
                        day = 1;
                    }
                } else {
                    if (day != 28) day ++;
                    else {
                        month ++;
                        day = 1;
                    }
                }
            } else {
                if (day != 30) day ++;
                else {
                    month ++;
                    day = 1;
                }
            }
        }
    }

    bool operator != (const date& a) const {
        return (this->day != a.day || this->month != a.month || this->year != a.year);
    }

    int* getArray() {
        int *array;
        array = new int[8];
        array[0] = year / 1000;
        array[1] = year % 1000 / 100;
        array[2] = year % 100 / 10;
        array[3] = year % 10;
        array[4] = month / 10;
        array[5] = month % 10;
        array[6] = day / 10;
        array[7] = day % 10; 

        return array;
    }
};

ostream & operator<< (ostream& out, const date& a) {
    out << a.year << ' ' << a.month << ' ' << a.day;
    return out;
}