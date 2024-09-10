#include <iostream>

const int N = 1e5 + 10;

int n, p, q;
long long prefix[N], diff[N], a[N];

using namespace std;

void difference() {
    for (int i = 1; i <= n; i ++) {
        diff[i] = a[i] - a[i - 1];
    }
}

void prefixSum() {
    for (int i = 1; i <= n; i ++) {
        a[i] = diff[i] + a[i - 1];
        prefix[i] = a[i] + prefix[i - 1];
    }
}

int main (void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    difference();

    for (int i = 0; i < p; i ++) {
        int l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }

    prefixSum();

    for (int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}