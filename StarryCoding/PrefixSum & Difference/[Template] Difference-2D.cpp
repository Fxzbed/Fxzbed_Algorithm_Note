#include <iostream>

const int N = 1e3 + 10;

using namespace std;

int n, m, q;
long long a[N][N], prefix[N][N], diff[N][N];

void difference2D() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            diff[i][j] += a[i][j];
            diff[i + 1][j] -= a[i][j];
            diff[i][j + 1] -= a[i][j];
            diff[i + 1][j + 1] += a[i][j]; 
        }
    }
}

void prefixSum2D() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            prefix[i][j] = diff[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    difference2D();

    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x2 + 1][y1] -= c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y2 + 1] += c;  
    }

    prefixSum2D();

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << prefix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}