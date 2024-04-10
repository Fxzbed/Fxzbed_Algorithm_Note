#include <bits/stdc++.h>

using namespace std;

int n, dp[11], ans = -1;

int main(void) {
    string s;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        dp[s.back() - '0'] = max(dp[s.front() - '0'] + 1, dp[s.back() - '0']);
    }

    for (int i = 0; i <= 9; i ++) {
        ans = max(ans, dp[i]);
    }

    cout << n - ans << endl;
}