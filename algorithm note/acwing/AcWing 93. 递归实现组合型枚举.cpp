#include <iostream>

using namespace std;

int o[25], n, m, idx;
bool ist[25];

void dfs(int u, int x) {
    if (u > m) {
        for (int i = 0; i < m - 1; i ++) cout << o[i] << ' ';
        cout << o[m - 1] << endl;
        return;
    }
    
    for (int i = 1; i <= n; i ++) {
        if (!ist[i] && i > x) {
            o[idx ++] = i;
            ist[i] = true;
            dfs(u + 1, i);    
            idx --;
            ist[i] = false;
        }
    }
}

int main(void) {
    cin >> n >> m;
    if (m != 0)
        dfs(1, 0);
    return 0;
}