#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N =  1e5;
int n;
int path[N];
bool isT[N];

void dfs(int u) {
    if (u == n) {
        //走到了头
        for (int i = 0; i < n; i ++) printf("%d ", path[i]);
        putchar('\n');
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (!isT[i]) {  //没走过    
            path[u] = i + 1;
            isT[i] = true;
            dfs(u + 1);
            isT[i] = false;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    dfs(0);
    return 0;
}