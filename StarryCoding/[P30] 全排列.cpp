#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
bool ist[N];
int a[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
        puts("");
        return;
    }

    for (int i = 1; i <= n; i ++) {
        if (!ist[i]) {
            a[u] = i;
            ist[i] = true;
            dfs(u + 1);
            ist[i] = false;
        }
    }
}

int main(void) {
    cin >> n;
    dfs(1);
    return 0;
}