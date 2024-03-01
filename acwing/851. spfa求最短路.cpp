#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

constexpr int N = 1e5 + 10;
int h[N], e[N], ne[N], d[N], n, m, dist[N], idx;
bool st[N];

void insert(int a, int b, int w) {
    e[idx] = b;
    ne[idx] = h[a];
    d[idx] = w;
    h[a] = idx ++;
}

bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int x = e[i];
            if (dist[x] > dist[t] + d[i]) {
                dist[x] = dist[t] + d[i];
                if (!st[x]) {
                    q.push(x);   
                    st[x] = true;
                }
            }
        }
    }
    
    return dist[n] == 0x3f3f3f3f;
}

int main(void) {
    // memset(d, 0x3f, sizeof d);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        
        insert(a, b, c);
    }
    
    int t = spfa();
    if (!spfa()) printf("%d\n", dist[n]);
    else puts("impossible");
    return 0;
}