#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e2 + 10;

int fa[N], n;

vector<int> g[N];

void dfs(int r) {
    cout << r << ' ';
    for (auto &x : g[r]) dfs(x);
}

void bfs(int r) {
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (auto& p : g[x]) {
            q.push(p);
        }
    }
}

int main(void) {
    cin >> n;
    
    for (int i = 2; i <= n + 2; i ++) cin >> fa[i];

    for (int i = 2; i <= n + 2; i ++) g[fa[i]].push_back(i);

    dfs(1);
    puts("");
    bfs(1);
        
    return 0;
}