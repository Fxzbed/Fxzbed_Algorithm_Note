#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
const int N = 2 * 1e2 + 10;
char m[N][N];
bool ist[N][N];
int t, a, b, dis[N][N];
pair<int, int> s;

void bfs() {
    queue<pair<int, int>> q;
    q.push(s);

    while (q.size()) {
        pair<int, int> t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < a && x >= 0 && y < b && y >= 0 && m[x][y] != '#' && !ist[x][y]) {
                if (m[x][y] == '.') {
                    q.push({x, y});
                    ist[x][y] = true;
                    dis[x][y] = dis[t.first][t.second] + 1;
                } else if (m[x][y] == 'E') {
                    cout << dis[t.first][t.second] + 1 << endl;
                    return;
                }
            }
        }
        /* code */
    }
    cout << "oop!" << endl;

}

int main(void){
    cin >> t;
    while (t --) {
        cin >> a >> b;
        for (int i = 0; i < a; i ++) {
            for (int j = 0; j < b; j ++) {
                cin >> m[i][j];
                if (m[i][j] == 'S') {
                    s = {i, j};
                }
            }
        }
        bfs(); 
        memset(ist, false, sizeof ist);
        memset(m, '#', sizeof m);
        memset(dis, 0, sizeof dis);
    }
    return 0;
}