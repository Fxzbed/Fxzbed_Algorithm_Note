#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll num[N], prefix[N], diff[N];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    
    for (int i = 1; i <= n; i ++) cin >> num[i];
    for (int i = 1; i <= n; i ++) diff[i] = num[i] - num[i - 1];

    int m; cin >> m;
    for (int i = 0; i < m; i ++) {
        int l, r, x;
        cin >> l >> r >> x;
        diff[l] += x, diff[r + 1] -= x;
    }

    for (int i = 1; i <= n; i ++) num[i] = diff[i] + num[i - 1];
    for (int i = 1; i <= n; i ++) prefix[i] = num[i] + prefix[i - 1];

    int q; cin >> q;
    for (int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    
    return 0;
}