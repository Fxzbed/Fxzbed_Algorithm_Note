#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

constexpr int N = 1e5 + 10;

int h[N], e[N * 2], ne[N * 2], d[N], idx, n, m, r_idx;
int res[N];
queue<int> q;

void insert(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
    d[b] ++; 
}

int main(void) {
        //init head queue
    memset(h, -1, sizeof h);
    memset(res, -1, sizeof res);
    
    cin >> n >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        
        insert(a, b);
    }
    
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 0) {
            q.push(i);
            res[r_idx ++] = i;
            // break;
        }
    }
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] --;
            if (d[j] == 0) {
                res[r_idx ++] = j;
                q.push(j);
            }
        }
    }
    
    if (res[n - 1] == -1) {cout << "-1" << endl; return 0;}
    for (int i = 0; i < n; i ++) {
        cout << res[i] << ' ';
    }
    return 0;
}