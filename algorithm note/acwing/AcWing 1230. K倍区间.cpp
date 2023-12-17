#include <iostream>

using namespace std;

const int N = 1e5 + 10;
long long n, k, a[N], an[N], sum, cnt[N];
long long res;

int main(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cnt[0] = 1;
    for (int i = 1; i <= n; i ++) {
        res += cnt[a[i] % k];
        cnt[a[i] % k] ++;
    }
    cout << res << endl;
    return 0;
}