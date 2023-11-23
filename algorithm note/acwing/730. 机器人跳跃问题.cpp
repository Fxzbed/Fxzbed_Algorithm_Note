#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N], res;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
 
    for (int i = n - 1; i >= 0; i --) res = (a[i] + res + 1) >> 1;
    cout << res;
    return 0;
}