#include <iostream>

using namespace std;

const int N = 35;

int n, m;
int dp[N][N];

int fdp() {
    dp[1][1] = 1;
    // dp[1][2] = 1;
    // dp[2][1] = 1;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++) {
            if (j % 2 + i % 2 == 0)
                continue;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }

    return dp[n][m];
}

int main(void) {
    cin >> n >> m;
    cout << fdp() << endl;
    

    
    // for (int i = 1; i <= n; i ++)
    //     for (int j = 1; j <= m; j ++)
    //         cout << "i:" << i << " j:" << j << ' ' << dp[i][j] << endl;
    return 0;
}