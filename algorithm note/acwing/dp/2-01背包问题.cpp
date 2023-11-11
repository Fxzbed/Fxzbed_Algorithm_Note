#include <iostream>

using namespace std;

constexpr int V = 1e3 + 10;
int n, m;
int f[V][V * V], v[V], w[V];

int dp() {
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++) {
            f[i][j] = f[i][j - 1];
            if (v[i] <= j) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    return f[n][m];
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) 
        cin >> v[i] >> w[i];
    
    cout << dp() << endl;
    return 0;
}