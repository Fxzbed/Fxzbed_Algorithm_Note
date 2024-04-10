#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char g[N][N];
bool ist[N][N];
int t, n, m, ans;

const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

bool check(int i, int j) {
    bool ist_[N][N];
    memset(ist_, false, sizeof ist_);
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i ++) {
            auto x = cur.first + dx[i];
            auto y = cur.second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m) return true;
            if (g[x][y] == '0' && !ist_[x][y]) {
                ist_[x][y] = true;
                q.push({x, y});
            }
        }
    }
    return false;
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    ist[i][j] = true;
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            auto x = cur.first + dx[i];
            auto y = cur.second + dy[i];
            if (x >= 0 && x < n && y < m && y >= 0 && g[x][y] == '1' && !ist[x][y]) {
                ist[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

void solve() {
    memset(g, '0', sizeof g);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (!ist[i][j] && g[i][j] == '1') {
                bfs(i, j);
                ans += check(i, j) ? 1 : 0;
            }
        }
    }
    cout << ans << '\n';
}



int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i ++) {
        solve();
        ans = 0;
        memset(ist, false, sizeof ist);
        memset(g, '0', sizeof g);
    }
}