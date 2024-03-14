#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

int q, o, x;
long long res;
priority_queue<int> qu;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    for (int i = 0; i < q; i ++) { 
        cin >> x;
        if (x == 1) {
            cin >> o;
            qu.push(o);
            res += o;
        } else if (!qu.empty()) {
            res -= qu.top();
            qu.pop();
        }
    }

    cout << res << '\n';
    return 0;
}