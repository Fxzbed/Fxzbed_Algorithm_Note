#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int N = 1e6;
bool pri[N];
double begin_T, end_T;
int primes[N], pp;

//朴素试除
inline bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= x / i; i ++) 
        if (x % i == 0) return false;
    return true;
}

inline bool isPrime_(int x) {
    if (x <= 1) return false;
    int sq = sqrt(x);
    for (int i = 2; i <= sq; i ++)  
        if (x % i == 0) return false;
    return true;
}

inline bool isPrime_Pro() {
    int res = 0;
    for (int i = 2; i <= N / i; i ++) {
        if (!pri[i])
            for (int j = i * i; j <= N; j += i) pri[j] = true;
    }

    for (int i = 2; i <= N; i ++) if (!pri[i]) res ++;
    cout << res << endl;

}

inline bool isPrime_ola() {
    int res = 0;
    for (int i = 2; i <= N; i ++) {
        if (!pri[i]) primes[++ pp] = i, res ++;
        for (int j = 1; primes[j] * i <= N && j <= pp; j ++) {
            pri[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    // for (int i = 2; i <= N; i ++) if (!pri[i]) res ++;
    cout << res << endl;
}

int main(void) {
    begin_T = clock();
    int cnt = 0;
    // for (int i = 2; i < N; i ++) {
    //     if (isPrime(i)) cnt ++;
    // }
    // cout << cnt;
    isPrime_Pro();
    end_T = clock();
    printf("\nrunning time = %.0lfms", end_T - begin_T);

    return 0;
}
