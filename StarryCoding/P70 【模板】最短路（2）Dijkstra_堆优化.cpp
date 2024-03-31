#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct node {
    long long v, w;
    bool operator < (const node& a) const {
        return this->w == a.w ? this->v > a.v : this->w > a.w;
    }
};

long long n, m, dis[N];
priority_queue<node> q;
bitset<N> ist;
vector<node> g[N];

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push({1, 0});

    while (q.size()) {
        auto x = q.top().v; 
        q.pop();

        if (ist[x]) continue;
        ist[x] = true;

        for (auto& t : g[x]) {
            if (!ist[t.v] && dis[x] + t.w < dis[t.v]) {
                dis[t.v] = dis[x] + t.w;
                q.push({t.v, dis[t.v]});
            }
        }
    }

    cout << (dis[n] >= 4e18 ? -1 : dis[n]) << '\n';
    return 0;
}