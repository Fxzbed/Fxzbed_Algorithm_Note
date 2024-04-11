#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a = 2022, res = 0;
    for (int i = 0; i < 4; i ++) {
        res += (a % 10) * pow(9, i);
        a /= 10;
    }
    cout << res << endl;
    return 0;
}