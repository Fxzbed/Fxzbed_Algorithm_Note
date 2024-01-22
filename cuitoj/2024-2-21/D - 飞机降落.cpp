#include <iostream>

const int N = 20;

using namespace std;

int t, n;
int T[N], D[N], L[N], DL[N];
bool ist[N], pass;

void dfs(int u, int time) {
    if (u == n) {
        pass = true;
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (pass) return;
        int time_ = time;
        if (!ist[i]) {
            if (time <= DL[i]) {
                if (time >= T[i]) time_ = time + L[i];
                else if (time < T[i]) time_ = T[i] + L[i];
                ist[i] = true;
                dfs(u + 1, time_);
                ist[i] = false;
            }
        }
    }

    return;
}

int main(void) {
    cin >> t;
    for (int i = 0; i < t; i ++) {
        cin >> n;
        for (int j = 0; j < n; j ++) {
            cin >> T[j] >> D[j] >> L[j];
            DL[j] = T[j] + D[j];
        }
        dfs(0, 0);
        if (pass) puts("YES");
        else puts("NO");
        pass = false;
    }
    return 0;
}