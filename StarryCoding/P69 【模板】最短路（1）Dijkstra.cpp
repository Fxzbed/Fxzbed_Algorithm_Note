#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

struct node {
    int v, w;
};

long long n, m, dist[N];
vector<node> g[N];
bitset<N> ist;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) g[u].push_back({v, w});
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i <= n; i ++) {
        int u = 1;
        for (int j = 1; j <= n; j ++) {
            if (ist[u] || (!ist[j] && dist[j] < dist[u])) u = j;
        }

        ist[u] = true;
        for (auto& [v, w] : g[u]) {
            if (!ist[v] && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    cout << (dist[n] == 0x3f3f3f3f ? -1 : dist[n]) << '\n';

    return 0;
}