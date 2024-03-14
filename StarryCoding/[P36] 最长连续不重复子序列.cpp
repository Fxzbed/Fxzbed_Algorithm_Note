#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int t, n, a[N], cnt[N];

void func() {
    memset(cnt, 0, sizeof cnt);
    int ans = 0;
    for (int i = 1;i <= n; i ++) cin >> a[i];
    for (int i = 1, j = 1;i <= n; i ++) {
        while (j <= n && !cnt[a[j]]) cnt[a[j++]]++;
        cnt[a[i]] --;
        ans = max(j - i, ans);
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t --) {
        cin >> n;
        func();
    }
    return 0;
}