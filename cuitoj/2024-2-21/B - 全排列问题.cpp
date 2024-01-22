#include <iostream>

const int N = 10;

using namespace std;

int n;
bool ist[N];
int nums[N];

void dfs(int u) {
    if (u == n + 1) {
        for (int i = 1; i <= n; i ++) {
            printf("%5d", nums[i]);
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i ++) {
        if (!ist[i]) {
            nums[u] = i;
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