#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 1e5 + 10;

/* 
    heap[index] -> value    heap是堆数组，index是他的下标
    heap_n[idx] -> index    heap_n是储存第k个插入堆数组的下标的数组
    heap_p[index] -> idx    heap_p是储存当前堆数组下标的k的数组
*/

int heap[N], heap_n[N], heap_p[N], size_, idx;

void heap_swap(int u, int t) {
    //heap_swap 对于交换次序不敏感 理顺数组下标与存值的意义即可
    swap(heap[u], heap[t]);
    swap(heap_p[u], heap_p[t]);
    swap(heap_n[heap_p[u]], heap_n[heap_p[t]]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= size_ && heap[u * 2] <= heap[t]) t = u * 2;
    if (u * 2 + 1 <= size_ && heap[u * 2 + 1] <= heap[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    if (u / 2 >= 1 && heap[u / 2] > heap[u]) {
        heap_swap(u / 2, u);
        up(u / 2);
    }
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);

    while (n --) {
        string opt; cin >> opt;

        if (opt == "I") {
            scanf("%d", &a);
            heap[++size_] = a;
            heap_n[++idx] = size_;
            heap_p[size_] = idx;
            up(size_);
        } else if (opt == "DM") {
            heap_swap(1, size_--);
            down(1);
        } else if (opt == "PM") {
            printf("%d\n", heap[1]);
        } else if (opt == "D") {
            scanf("%d", &a);
            int t = heap_n[a];  //heap_n 在heap_swap后就被改变 在这里存储一次
            heap_swap(heap_n[a], size_--);
            up(t);      
            down(t);
        } else if (opt == "C") {
            scanf("%d%d", &a, &b);
            heap[heap_n[a]] = b;
            up(heap_n[a]);
            down(heap_n[a]);
        }
        // cout << opt << endl;
    }
    return 0;
}