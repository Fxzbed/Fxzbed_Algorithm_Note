#include <iostream>
#include <cstring>
#include <queue>

const int N = 410;
const int m_x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int m_y[8] = {1, -1, 1, -1, 2, -2, 2, -2};

using namespace std;

int res[N][N], n, m, x, y;
bool ist[N][N];

void bfs() {
    queue<pair<int, int>> q;
    q.push({x, y});
    res[x][y] = 0;
    ist[x][y] = true;

    while (q.size()) {
        int nx = q.front().first, ny = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i ++) {
            int x_ = nx + m_x[i], y_ = ny + m_y[i];
            if (y_ <= m && y_ >= 1 && x_ >= 1 && x_ <= n && !ist[x_][y_]) {
                res[x_][y_] = res[nx][ny] + 1;
                q.push({x_, y_});
                ist[x_][y_] = true;
            }
        }
    }
    return;
}

int main(void) {
    memset(res, -1, sizeof res);
    cin >> n >> m >> x >> y;
    bfs();
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            printf("%5d", res[i][j]);
        }
        puts("");
    }
    return 0;
}