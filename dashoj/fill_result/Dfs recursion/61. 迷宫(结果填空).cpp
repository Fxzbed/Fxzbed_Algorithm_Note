#include <bits/stdc++.h>

using namespace std;

char g[31][51];
int sh[31][51];

string processStr[31][51];

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};

char addStr(int i) {
    if (i == 0) return 'D';
    else if (i == 1) return 'L';
    else if (i == 2) return 'R';
    else if (i == 3) return 'U';
    return 'e';
}

void bfs() {
    memset(sh, -1, sizeof sh);
    sh[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});

    processStr[1][1] = "";
 
    while (q.size()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++) {
            auto x = t.first + dx[i];
            auto y = t.second + dy[i];
            if (x < 1 || x > 30 || y < 1 || y > 50 || g[x][y] == '1' || sh[x][y] != -1) continue;
            sh[x][y] = sh[t.first][t.second] + 1; 
            processStr[x][y] = processStr[t.first][t.second] + addStr(i);
            q.push({x, y});
        }
    }   
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x_, y_;
    cin >> x_ >> y_;
    for (int i = 1; i <= x_; i ++) {
        for (int j = 1; j <= y_; j ++) {
            cin >> g[i][j];
        }
    } 

    bfs();
    cout << sh[x_][y_] << endl;
    cout << processStr[x_][y_];
}