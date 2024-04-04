#include <bits/stdc++.h>

using namespace std;

double n[9];
int res = 0;

int main(void) {
    int idx = 0;
    for (int i = 1; i <= 9; i ++) {
        n[idx ++] = (double)i;
    }

    do {
        double d = n[3] * 100 + n[4] * 10 + n[5];
        double e = n[6] * 100 + n[7] * 10 + n[8];
        double down = n[2] * e;
        double up = (n[1] * e) + (n[2] * d);
        if (n[0] + (up / down) == 10.0) {
            cout << n[0] << ' ' << n[1] << '/' << n[2] << ' ' << d << '/' << e << " " << up << ' ' << down << '\n';
            res ++;
        }
    } while (next_permutation(n, n + 9));
    
    cout << res;
    return 0;
}