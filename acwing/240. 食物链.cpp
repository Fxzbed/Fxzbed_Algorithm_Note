#include <iostream>

using namespace std;

constexpr int N = 1e4 * 5;
int p[N], d[N];

/*
    0 - 1
    2 - 0
    0 = 3
*/

int find(int x) {
    int t = 0;
    if (p[x] != x) {
        t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i ++) p[i] = i;

    int res = 0;
    while (k --) {
        int opt, a, b;
        scanf("%d%d%d", &opt, &a, &b);

        if (a > n || b > n || (a == b && opt == 1)) {
            res ++;
        } else if (opt == 1) {
            int p_a = find(a), p_b = find(b);
            if (p_a == p_b && (d[a] % 3 || d[b] % 3)) res ++;
            else if (p_a != p_b) {
                p[p_a] = p[p_b];
                d[p_a] = d[b] - d[a];
            }
        } else if (opt == 2) {
            int p_a = find(a), p_b = find(b);
            if (p_a == p_b && (d[a] % 3 != 1 || d[b] % 3 != 1)) res ++;
            else if (p_a != p_b) {
                p[p_a] = p[p_b];
                d[p_a] = p[b] + 1 - p[a];
            }
        }
    }

    printf("%d", res);

    return 0;
}