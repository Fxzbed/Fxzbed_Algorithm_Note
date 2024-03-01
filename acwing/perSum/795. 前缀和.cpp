#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], an[N], n, m;

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        an[i] = an[i - 1] + a[i];
    }

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        cout << an[r] - an[l - 1] << endl; 
    }
    return 0;
}