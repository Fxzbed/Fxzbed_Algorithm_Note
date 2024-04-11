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

int res;
int num[100]{
		5,6,8,6,9,1,6,1,2,4,
		9,1,9,8,2,3,6,4,7,7,
		5,9,5,0,3,8,7,5,8,1,
		5,8,6,1,8,3,0,3,7,9,
		2,7,0,5,8,8,5,7,0,9,
		9,1,9,4,4,6,8,6,3,3,
		8,5,1,6,3,4,6,7,0,7,
		8,2,7,6,8,9,5,6,5,6,
		1,4,0,1,0,0,9,4,8,0,
		9,1,2,8,5,0,2,5,3,3 };

bool search(int* a) {
    int times = 0;
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 100; j ++) {
            if (num[j] == a[i]) {
                times ++;
                i ++;
            }
            if (times == 8) {
                delete a;
                return true;
            }
        }
        return false;
    }
    return false;   
}

int main(void) {
    date a = {2023, 1, 1};

    do {
        if (search(a.getArray())) {

            res ++;
        }
        a ++;
    } while (a.year != 2024);

    cout << res << endl;

    return 0;
}