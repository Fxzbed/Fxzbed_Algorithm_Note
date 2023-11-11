#include <iostream>

using namespace std;

const int N = 10010;

int f[N][N], v[N], w[N], n, m;

int main(void) {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
        }
            
    cout << f[n][m];
    return 0;
}
//未优化空间的版本
