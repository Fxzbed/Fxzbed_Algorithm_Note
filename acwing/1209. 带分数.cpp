#include <iostream>
#include <cstring>

const int N = 20;

using namespace std;

int n;
int a, b, c, ans;
bool ist[N], backup[N];

bool check(int a, int c) {
    int b = c * (n - a);
    if (!a || !c || !b) return false;
    memcpy(backup, ist, sizeof ist);

    while (b) {
        int x = b % 10;
        b /= 10;
        if (!x || backup[x]) return false;
        backup[x] = true;
    }

    for (int i = 1; i <= 9; i ++) {
        if (!backup[i]) return false;
    }

    return true;
}

void dfs_c(int u, int a, int c) {
    if (u > 9) return;

    if (check(a, c)) ans ++;

    for (int i = 1; i <= 9; i ++) {
        if (!ist[i]) {
            ist[i] = true;
            dfs_c(u + 1, a, c * 10 + i);
            ist[i] = false;
        } 
    }
}

void dfs_a(int u, int a) {
    if (a >= n) return;
    dfs_c(u, a, 0);

    for (int i= 1; i <= 9; i ++) {
        if (!ist[i]) {
            ist[i] = true;
            dfs_a(u + 1, a * 10 + i);
            ist[i] = false;
        }
    }
}


int main(void) {
    cin >> n;
    dfs_a(0, 0);
    cout << ans << endl;
    return 0;
}