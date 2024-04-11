// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e4 + 10;

// int n, h[N], m[N];
// bool dx;

// void pass_day() {
//     for (int i = 0; i < n; i ++) {
//         h[i] ++;
//     }
// }

// void caculate_max() {
//     for (int i = 0; i < n; i ++) {
//         m[i] = max(m[i], h[i]);
//     }
// }

// void solve() {
//     for (int i = 0; i < 9999; i ++) {
//         for (int j = 0; j < n - 1; j ++) {
//             pass_day();
//             caculate_max(); 
//             h[j] = 0;
//         }

//         for (int j = n - 1; j > 0; j --) {
//             pass_day();
//             caculate_max();
//             h[j] = 0;
//         }
//     }
//     cout << n << ": ";
//     for (int i = 0; i < n; i ++) cout << m[i] << ' ';
//     cout << endl;
// }

// int main(void) {
//     for (n = 1; n <= 12; n ++)  solve();
//     return 0;


// }

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, h[N], idx;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;

    if (n % 2) {
        idx = n / 2 + 1;
        h[idx] = n - 1;
        // cout << idx << ' ' << h[idx] << endl;
        for (int i = idx - 1; i >= 1; i --) {
            h[i] = h[i + 1] + 2;
            // cout << i << ' ' << h[i] << ' ' << h[i + 1] + 2 << endl; 
            h[n - i + 1] = h[i];
        }
    } else {
        idx = n / 2;
        int initV = n;
        for (int i = idx; i > 0; i --) {
            h[i] = initV;
            h[n - i + 1] = h[i];
            initV += 2;
        }
    }

    for (int i = 1; i <= n; i ++) cout << h[i] << endl;
    return 0;
}