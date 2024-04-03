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
};

ostream & operator<< (ostream& out, const date& a) {
    out << a.year << ' ' << a.month << ' ' << a.day;
    return out;
}

long long res = 0;

int main(void) {
    date a = {1921, 7, 23};
    date t = {2020, 7, 1};
    while (a != t) {
        a ++;
        res ++;
    }

    cout << res * 24 * 60 << endl;
}