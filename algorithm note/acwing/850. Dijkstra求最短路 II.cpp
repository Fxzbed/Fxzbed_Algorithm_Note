#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
//堆优化后的dijkstra
using namespace std;

constexpr int N = 15e4 + 10;
int h[N], e[N * 2], ne[N * 2], idx, n, m, w[N], dist[N];
bool st[N]; 

void insert(int a, int b, int c) {
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    
    dist[1] = 0;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int index = t.second, dis = t.first;
        if (st[index]) continue;
        else st[index] = true;

        for (int i = h[index]; i != -1; i = ne[i]) {
            auto j = e[i];
            if (w[i] + dis < dist[j]) {
                dist[j] = w[i] + dis;
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
} 



int main(void) {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        insert(a, b, c);
    }

    cout << dijkstra() << endl;
    return 0;
}