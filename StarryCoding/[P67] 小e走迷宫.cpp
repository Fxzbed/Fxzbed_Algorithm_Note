#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 5;

const int move_x[4] = {0, 0, 1, -1};
const int move_y[4] = {1, -1, 0, 0};

bool g[N][N];
int n, m;
int step[N][N];

void bfs(int i, int j) {
    auto isR = [](int x, int y) -> bool {
        return x >= 1 && y >= 1 && x <= n && y <= m;
    };
    queue<pair<int, int>> q;
    memset(step, -1, sizeof step);
    q.push({i, j});
    step[i][j] = 0;
    while (q.size()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            auto x = now.first + move_x[i];
            auto y = now.second + move_y[i];
            if (isR(x, y) && !g[x][y]) {
                g[x][y] = true;
               	q.push({x,y}); 
                step[x][y] = step[now.first][now.second] + 1;
            }
        }
    }   
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++) 
            cin >> g[i][j];
    
    bfs(1, 1);

    cout << step[n][m];

    return 0;
}