#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int N = 1e5 + 10;

int h[N], e[N * 2], d[N], ne[N * 2], idx, n, m;
queue<int> q;   //放节点名

int dfs(int u) {
    d[1] = 0;   //初始化d[1]为0，1到d[1]的距离为0
    q.push(1);  
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                q.push(j);
                d[j] = d[t] + 1;
            }
        }
    }
    return d[n];
}

void insert(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main(void) {
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    cin >> n >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        
        insert(a, b);
    }
    
    cout << dfs(1) << endl;
    return 0;
}