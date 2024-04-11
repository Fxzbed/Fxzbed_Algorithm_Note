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
};

ostream & operator<< (ostream& out, const date& a) {
    out << a.year << ' ' << a.month << ' ' << a.day;
    return out;
}

int main(void) {
    date a = {2014, 11, 9};
    int pass = 1000;
    while (pass --) a ++;
    
    cout << a << endl;
}