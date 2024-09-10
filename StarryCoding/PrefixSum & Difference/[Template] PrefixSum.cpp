#include <iostream>

const int N = 1e5 + 10;

int T, n, q;
long long a[N];

using namespace std;

void prefixSum() {
    for (int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
    }
}

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> q;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }

        prefixSum();

        for (int j = 0; j < q; j++) {
            int l, r;
            cin >> l >> r;
            cout << a[r] - a[l - 1] << endl; 
        }
    }
    return 0;
}
