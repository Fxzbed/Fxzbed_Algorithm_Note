#include <bits/stdc++.h>

using namespace std;

vector<int> sorce[20];
int select[5], maxV;
bool ist[20];

void check() {
    for (int i = 0; i < 5; i ++) cout << select[i] << ' ';
    puts("");
    int tmp = 0;
    for (int i = 0; i < 5; i ++) {
        tmp += sorce[select[i]][i];
    }
    maxV = maxV > tmp ? maxV : tmp;
    return;
}

void dfs(int u) {
    if (u == 5) {
        check();
        return;
    }

    for (int i = 0; i < 20; i ++)   
        if (!ist[i]) {
            ist[i] = true;
            select[u] = i;
            dfs(u + 1);
            ist[i] = false;
        }
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 20; i ++) {
        int idx; cin >> idx;
        for (int j = 0; j < 5; j ++) {
            int tmp; cin >> tmp;
            sorce[i].push_back(tmp);
        }
    }

    dfs(0);

    cout << maxV;

    return 0;
}