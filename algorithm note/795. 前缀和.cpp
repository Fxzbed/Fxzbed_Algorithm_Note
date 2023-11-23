#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int l, r, n, m;
int a[N], an[N];

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        an[i] = a[i] + an[i - 1];
    }

    for (int i = 0; i < m; i ++) {
        cin >> l >> r;
        // cout << an[r] << ' ' << an[l - 1] << endl;
        cout << an[r] - an[l - 1] << '\n';  
    }
    return 0;
}