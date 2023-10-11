#include <iostream>

using namespace std;

const int N = 10e5 + 10;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];  
}

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    }

    while (m --) {
        char op;
        int tmp1, tmp2;
        cin >> op >> tmp1 >> tmp2;

        if (op == 'M') {
            p[find(tmp1)] = find(tmp2);
        } else {
            if (find(tmp1) == find(tmp2)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
} 