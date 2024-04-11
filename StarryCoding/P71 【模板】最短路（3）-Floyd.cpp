#include <bits/stdc++.h>

using namespace std;

const int N = 305, inf = 4e18;

long long n, m, q, dist[N][N];

int main(void) {
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i ++) {
        long long u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);    //重边取最小值
    }

    for (int i = 1; i <= n; i ++) dist[i][i] = 0;

    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    while (q --) {
        long long u, v;
        cin >> u >> v;
        cout << (dist[u][v] >= inf ? -1 : dist[u][v]) << '\n';
    }
    return 0;
}