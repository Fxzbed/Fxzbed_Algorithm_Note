#include <bits/stdc++.h>

using namespace std;

int a[] = {1, 1, 2, 2, 3, 3, 4, 4};
int out[8];
bool ist[8], done;

bool check() {
    bool ist_[5];
    memset(ist_, false, sizeof ist_);
    for (int i = 0; i < 8; i ++) 
        if (!ist_[1] && out[i] == 1) {
            for (int j = i + 1; j < 8; j ++) {
                if (out[j] == 1) {
                    if (j - i - 1 != 1) return false;
                    ist[1] = true;
                    break;
                }
            }

        if (!ist_[2] && out[i] == 2) 
            for (int j = i + 1; j < 8; j ++) {
                if (out[j] == 2) {
                    if (j - i - 1 != 2) return false;
                    ist[2] = true;
                    break;
                }
            }

        if (!ist_[3] && out[i] == 3) 
            for (int j = i + 1; j < 8; j ++) {
                if (out[j] == 3) {
                    if (j - i - 1 != 3) return false;
                    ist[3] = true;
                    break;
                }
            }

        if (!ist_[4] && out[i] == 4) 
            for (int j = i + 1; j < 8; j ++) {
                if (out[j] == 4) {
                    if (j - i - 1 != 4) return false;
                    ist[4] = true;
                    break;
                }
            }
    }
    return true;
}
void dfs(int u) {
    if (done) return;
    if (u == 8) {
        if (check()) {
            for (int i = 0; i < 8; i ++) {
                if (out[i] == 1) cout << 'A';
                else cout << out[i];
            }
            puts("");
            done = true;
        }
        return;
    }

    for (int i = 0; i < 8; i ++) {
        if (!ist[i]) {
            ist[i] = true;
            out[u] = a[i];
            dfs(u + 1);
            ist[i] = false;
        }
    }
}

int main(void) {
    dfs(0);
    return 0;
}