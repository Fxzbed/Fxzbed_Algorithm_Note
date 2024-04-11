#include <iostream>

using namespace std;

bool DecTrans(long long x, const int i) {
    auto tmp = x;
    long long s = 0;
    while (tmp) {
        s += tmp % i;
        tmp /= i;
    }
    if (x % s == 0) return true;
    return false;
}

bool ist(long long x) {
    auto tmp = x;
    return (DecTrans(x, 2) && DecTrans(x, 8) && DecTrans(x, 10) && DecTrans(x, 16));
}

int times;

int main(void) {
    int res = 0;
    while (times == 2023) {
        if (ist(++res)) {
            times ++;
        }
    }
    cout << res;
    return 0;
}