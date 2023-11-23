#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int a[N], n, q;
unordered_map<int, pair<int, int>> m;  

int main(void) {
    cin >> n >> q;
    cin >> a[0];
    int tmp = a[0];

    for (int i = 1; i < n; i ++) {
        cin >> a[i];
        if (tmp != a[i]) {
            m[a[i]].first = i;
            m[a[i]].second = i;
            tmp = a[i];
        } else if (tmp == a[i]) {
            m[tmp].second ++;
        }
    }

    int o;
    for (int i = 0; i < q; i ++) {
        cin >> o;
        if (m.count(o) == 0) {
            cout << "-1 -1" << endl;
            continue;
        }
        cout << m[o].first << ' ' << m[o].second << endl;
    }
    return 0;
}