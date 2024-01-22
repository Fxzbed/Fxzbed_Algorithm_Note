#include <iostream>
#include <cstring>

const int N = 10;

using namespace std;

int nums[N];
int n;
bool ist[N];

void dfs(int u) {
    if (u == n + 1) {
        for (int i = 1; i <= n - 1; i ++) {
            cout << nums[i] << ' ';
        }
        cout << nums[n] << endl;
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (!ist[i]) {
            nums[u] = i + 1;
            ist[i] = true;
            dfs(u + 1); 
            ist[i] = false;
        }
    }
}

int main(void) {
    memset(ist, false, sizeof ist);
    cin >> n;
    dfs(1);
    return 0;
}