#include <iostream>

using namespace std;

const int N = 3e5 + 10;

int n, q;
long long t[N], a[N];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    auto lowbit = [&](int u) -> int {return u & (-u);};

    auto addT = [&](long long k, long long v) {
        for (int i = k; i <= n; i += lowbit(i)) 
            t[i] += v;
    };

    auto getSum = [&](int k) -> long long {
        long long res = 0;
        for (int i = k; i > 0; i -= lowbit(i)) 
            res += t[i];
        return res;
    };

    auto output = [&](long long l, long long r) {
        cout << getSum(r) - getSum(l - 1) << '\n';
    };

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        addT(i, a[i]);
    }
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            long long k, v;
            cin >> k >> v;
            addT(k, v);
        } else {
            long long l, r;
            cin >> l >> r;
            output(l, r);
        }
    }
    return 0;
}