#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 1e5 + 10;

int h[N], edge, n, m;

void down(int i) {
    int t = i;
    if (i * 2 <= edge && h[i * 2] < h[t]) t = i * 2;
    if (i * 2 + 1 <= edge && h[i * 2 + 1] < h[t]) t = i * 2 + 1;
    if (t != i) {
        swap(h[t], h[i]);
        down(t);
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    edge = n;

    for (int i = n / 2; i; i--) down(i);

    while (m --) {
        printf("%d ", h[1]);
        h[1] = h[edge];
        edge --;
        down(1);
    }

    return 0;
}

/*#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 1e5 + 10;

int heap[N], n, m, heapSize;

void down(int i) {
    int m = i;
    if (i * 2 <= heapSize && heap[i * 2] < heap[m]) m = i * 2;
    if (i * 2 + 1 <= heapSize && heap[i * 2 + 1] < heap[m]) m = i * 2 + 1;
    if (i != m) {
        swap(heap[i], heap[m]);
        down(m);
    }
}

int main(void) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) scanf("%d", &heap[i]);
    heapSize = n;

    for (int i = n / 2; i ; i --) down(i);
    
    while (m --) {
        printf("%d ", heap[1]);
        heap[1] = heap[heapSize];
        heapSize --;
        down(1);
    }

    return 0;
}*/