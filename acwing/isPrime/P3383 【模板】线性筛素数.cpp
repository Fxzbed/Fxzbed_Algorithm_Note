#include <iostream>
#include <bitset>

using namespace std;

const int maxn = 1e8 + 10;

int n, q, primes[maxn], pp;
bitset<maxn> st;

// inline void ola(int n) {
//     for (int i = 2; i <= n; i ++) {
//         if (!ist[i]) primes[++pp] = i;
//         for (int j = 1; primes[j] * i <= n; j ++) {
//             ist[primes[j] * i] = 1;
//             if (i % primes[j] == 0) break;
//         }
//     }
//     return;
// }

inline void ola(int n) {
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[++pp] = i;
        for (int j = 1; primes[j] * i <= n; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(0);
    cin >> n >> q;

    ola(n);

    while (q --) {
        int k;
        cin >> k;
        cout << primes[k] << endl;
    }

    return 0;
}

