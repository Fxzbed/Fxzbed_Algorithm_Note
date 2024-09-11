#include <iostream>

const int N = 1e5 + 10;

using namespace std;

int T, n, a[N];
bool isMorD[N];
long long prefix[N], minPrefix[N], ess, ans;

void prefixSum() {
    for (int i = 1; i <= n; i ++ ) {
        prefix[i] = a[i] + prefix[i - 1];
        minPrefix[i] = min(minPrefix[i - 1], prefix[i]);
    }
}

int main(void) {
    ess = 0;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T --) {
        ess = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> isMorD[i];
        }

        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            if (isMorD[i]) {
                ess += a[i];
                a[i] *= -1;
            }
        }

        ans = ess;
        prefixSum();

        for (int i = 1; i <= n; i ++) {
            ans = max(ans, ess + prefix[i] - minPrefix[i - 1]);
        }

        cout << ans << endl;
    }
    return 0;
}