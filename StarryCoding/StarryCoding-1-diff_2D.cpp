#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e3 + 10;
int q, n, m, a[N][N], diff[N][N];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            diff[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]; 
        }
    }
    
    for (int i = 0; i < q; i ++) {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }
    return 0;
}