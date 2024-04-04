#include <bits/stdc++.h>

using namespace std;

int t;

int ans(int u) {
    int res = 2, i = 0;
    while (i != u) {
        res += pow(2, i++);
    }
    return res;
}

int main(void) {
    cout << ans(10);
    return 0;
}