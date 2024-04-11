#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long n, ma, num[N], ma_, num_[N], m[N], ans;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> ma;
    for (int i = ma - 1; i >= 0; i --) cin >> num[i];
    cin >> ma_;
    for (int i = ma_ - 1; i >= 0; i --) cin >> num_[i];
    long long base = 1;
    for (int i = 0; i < ma; i ++) {
        m[i] = max(num[i], num_[i]) + 1;
        if (m[i] < 2) m[i] = 2;
        ans += ((num[i] - num_[i]) * base);
        ans %= 1000000007;
        base *= m[i];
        base %= 1000000007;
    }

    cout << ans % 1000000007 << endl;
    return 0;
}