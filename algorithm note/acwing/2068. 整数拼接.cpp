#include <iostream>

using namespace std;

const int N = 1e5 + 10;

long long n, k, a[N];
long long res;
int s[11][N];

int main(void) {
    cin >> n >> k;
    //枚举
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) {
        long long t = a[i] % k;
        for (int j = 0; j < 11; j ++) {
            s[j][t] ++;
            t = t * 10 % k;
        }
    }
    //query
    for (int i = 0; i < n; i ++) {
        long long t = a[i] % k;
        int len = to_string(a[i]).size();
        res += s[len][(k - t) % k];
    //去重
        long long r = t;
        while (len --) r = r * 10 % k;
        if (r == (k - t) % k) res --; 
    }                                   

    cout << res << endl;
}