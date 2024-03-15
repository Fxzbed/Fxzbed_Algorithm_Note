#include <iostream>
#include <bitset>

using namespace std;

const int N = 5e5 + 10;

int n;
bitset<N> bs;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    bs[0] = 1;
    while (n --) {
        int t; cin >> t;
        bs |= (bs << t);
    }

    cout << bs.count() << '\n';

    return 0;
}

/*
二维存在性dp:

#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int n, a[N];
bool dp[N][N];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= 5e3; j ++) {
            dp[i][j] = dp[i - 1][j];    //拿回上一次的结果
            if (j >= a[i]) {
                dp[i][j] |= dp[i - 1][j - a[i]];    //在上一次能够组成 j-a[i] 的值，此时到达第a[i]，可以为上一次能组成的数都加上a[i]，所以选择 j-a[i]
            }
        }
    }
    long long res = 0;
    for (int i = 0; i <= 5e3; i ++) {
        res += dp[n][i];
    }
    cout << res << endl;
    return 0;
}

对于一维存在性dp
#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int n, a[N];
bool dp[N];
long long res;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= N; i ++) {
        for (int j = N; j >= a[i]; j --) {
            dp[j] |= dp[j - a[i]];
        }
    }

    for (int i = 0; i <= N; i ++) 
        if (dp[i]) res ++;
    
    cout << res << '\n';
    return 0;
}
*/

