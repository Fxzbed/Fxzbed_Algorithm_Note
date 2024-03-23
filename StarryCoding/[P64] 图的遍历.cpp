#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m, fa[N];
bool ist[N];
vector<int> g[N];
vector<int> output;

void bfs(int r) {
    queue<int> q;
    q.push(r);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (ist[x]) continue;
        ist[x] = true;
        output.push_back(x);
        for (auto& p : g[x]) {
            if (!ist[p]) {
                q.push(p);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        
        g[u].push_back(v);
    }

    // for (int i = 1; i <= n; i ++) {
    //     sort(g[i].begin(), g[i].end());
    //     unique(g[i].begin(), g[i].end());
    // }
    bfs(1);
    sort(output.begin(), output.end());
    //for (auto& x : output) cout << x << ' ';
    for (int i = 1; i <= n; i ++) if(ist[i]) cout << i << ' ';
    return 0;
}

//ist记录到过的点消除重边与环，同时记录了到达的点，天然排序