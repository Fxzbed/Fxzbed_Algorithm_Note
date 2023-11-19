#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n, a[N], res;

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) {
        if (a[i] != i) {
            for (int j = i + 1; j <= n; j ++) {
                if (a[j] == i) {
                    swap(a[i], a[j]);
                    res ++;
                }
            }
        }
    }
    cout << res;
    return 0;
}