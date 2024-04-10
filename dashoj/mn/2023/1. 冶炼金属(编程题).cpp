#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, a[N], b[N];
int max_;

bool check(int mid) {
    for (int i = 0; i < n; i ++) {
        if (b[i] != a[i] / mid) return false;
    }
    return true;
}

int binary_search_min(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int binary_search_max(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r;
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i] >> b[i];
    max_ = a[0] / b[0];
    for (int i = 0; i < n; i ++) max_ = min(max_, a[i] / b[i]);
    int ans_min = binary_search_min(1, max_);
    cout << ans_min << ' ' << binary_search_max(ans_min, max_) << '\n';
}