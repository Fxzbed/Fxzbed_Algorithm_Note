#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

long long prefix[N], num[N], mins[N], animal[N];
long long t, n, fix, ess;

int main(void) {
    cin >> t;

    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            int a; cin >> a;
            if (a == 0)
                animal[i] = 1;
            else 
                animal[i] = -1;
        }

        for (int i = 1; i <= n; i ++) {
            cin >> num[i];
            if (animal[i] == -1)
                ess += num[i];
            num[i] *= animal[i];
        }

        ll min_n = 0;

        for (int i = 1; i <= n; i ++) {
            prefix[i] = num[i] + prefix[i - 1];
            min_n = min(min_n, prefix[i]);
            mins[i] = min_n;
        }

        for (int r = 1; r <= n; r ++) {
            fix = max(fix, prefix[r] - mins[r - 1]);
        }

        cout << fix + ess << endl;

        fix = 0, ess = 0;
        memset(prefix, 0, sizeof prefix);
        memset(num, 0, sizeof num);
        memset(mins, 0, sizeof mins);
        memset(animal, 0, sizeof animal);
    }
    return 0;
}