#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

constexpr int N = 510;
int dist[N], g[N][N], n, m;
bool isT[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 1; j <= n; j ++) 
            if (!isT[j] && (t == -1 || dist[t] > dist[j])) 
                t = j;

        
        isT[t] = true;
        for (int j = 1; j <= n; j ++) 
            dist[j] = min(dist[j], dist[t] + g[t][j]);

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
    
    int res = dijkstra();
    
    cout << res << endl;
}