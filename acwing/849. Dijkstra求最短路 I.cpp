#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
//没有优化过的dijkstra
using namespace std;

constexpr int N = 510;

int g[N][N], dist[N], n, m;
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 1; j <= n; j ++) 
            if (!st[j] && (t == -1 || dist[t] > dist[j])) 
                t = j;
                
        st[t] = true;
        for (int j = 1; j <= n; j ++) 
            dist[j] = min(dist[j], dist[t] + g[t][j]);  //各个点从1到j的距离    t是已经选中的这一步走的最短距离
    }
    
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main(void) {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        
        g[a][b] = min(g[a][b], c);
    }
    
    cout << dijkstra() << endl;
    return 0;
}