//打表
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


/*

获得数据如下
1: 0
2: 2 2
3: 4 2 4
4: 6 4 4 6
5: 8 6 4 6 8
6: 10 8 6 6 8 10
7: 12 10 8 6 8 10 12
8: 14 12 10 8 8 10 12 14
9: 16 14 12 10 8 10 12 14 16
10: 18 16 14 12 10 10 12 14 16 18
11: 20 18 16 14 12 10 12 14 16 18 20
12: 22 20 18 16 14 12 12 14 16 18 20 22

*/

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
        for (int i = idx - 1; i >= 1; i --) {
            h[i] = h[i + 1] + 2; 
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
