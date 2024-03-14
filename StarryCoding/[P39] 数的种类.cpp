#include <iostream>
#include <map>

using namespace std;

const int N = 5e3 + 10;

int n, a[N];
long long res;
map<int, bool> m;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    

    cout << res << '\n';

    return 0;
}