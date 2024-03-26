#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 10;

struct cmp {
    bool operator() (const int& a, const int& b) const {
        return a > b;
    }
};

int n, m;
vector<int> g[N], getin[N];
priority_queue<int, vector<int>, cmp> q_;
bool ist[N];


void bfs(int u) {
    int res = 0;
    if (!ist[u]) {
        res ++;
        ist[u] = true;
    } else return;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (auto &x : g[t]) {
            if (ist[x]) continue;
            res ++;
            q.push(x);
            ist[x] = true;
        }
    }
    if (res != 0) q_.push(res);
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i ++) bfs(i);

    while (!q_.empty()) {
        cout << q_.top() << ' ';
        q_.pop();
    }

    return 0;
}