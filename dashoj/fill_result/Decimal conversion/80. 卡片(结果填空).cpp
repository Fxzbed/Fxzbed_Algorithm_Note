#include <iostream>
#include <cstring>

using namespace std;
int a[10], res;
int main(void) {
    while (++res) {
        auto t = res;
        while (t) {
            int bit = t % 10;
            a[bit] ++;
            if (a[bit] == 2022) {
                cout << res;
                return 0;
            }
            t /= 10;
        }
    }
}