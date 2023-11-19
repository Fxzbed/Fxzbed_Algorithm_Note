#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, e[N], ne[N], h[N], deep, idx, tm;
pair<int, int> res;
//1 2 4 8 16

int main(void) {
    deep = 1;
    cin >> n;
    int t;
    cin >> t;
    res = {1, t};
    for (int i = 2; i <= n; i ++) {
        cin >> t;
        if (i < 2 * deep + 1) {
            tm += t;
        } else {
            if (tm > res.second) {
                res = {deep, tm};
            }
            deep ++;
            tm = 0;
        }
    }

    cout << res.first;
    return 0;
}