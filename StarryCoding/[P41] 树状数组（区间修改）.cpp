#include <iostream>

using namespace std;
using ll = long long;

const int N = 3e5 + 10;

int n, q;
long long a[N], t1[N], t2[N];

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    auto lowbit = [&](int u) -> auto {return u & (-u);};

    auto add = [&](int k, ll v) {
        for (int i = k; i <= n; i += lowbit(i)) {
            t1[i] += v;
            t2[i] += k * v;
        }
    };

    auto getsum= [&](int k) {
        ll res = 0;
        for (int i = k; i > 0; i -= lowbit(i)) res += (k + 1) * t1[i] - t2[i];
        return res;
    };

    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        add(i, a[i]);
        add(i + 1, -a[i]);
    }

    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            add(l, v);
            add(r + 1, -v);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << getsum(r) - getsum(l - 1) << '\n';
        }
    }

    return 0;
}