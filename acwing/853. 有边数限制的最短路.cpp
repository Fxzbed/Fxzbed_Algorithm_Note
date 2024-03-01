#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 510, M = 1e5 + 10;

struct edge {
    int a;
    int b;
    int w;
};
edge E[M];  //为了遍历所有的边

int dist[N], n, m, k, backup[N];

bool bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i ++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++) {
            int a = E[j].a, b = E[j].b, w = E[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    
    if (dist[n] > 0x3f3f3f3f / 2) return false;
    return true;
}

int main(void) {
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        E[i] = {a, b, c};
    }
    
    if (bellman_ford()) 
        cout << dist[n] << '\n';
    else 
        cout << "impossible" << '\n';
    
    return 0;
}