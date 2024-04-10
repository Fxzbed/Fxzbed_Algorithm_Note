#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T[N], D[N], L[N];

bool check(const int n, int* arr) {
    bool ist = false;
    int begin = 0;
    for (int i = 0; i < n; i ++) {
        auto idx = arr[i];
        if (i == 0) begin = T[idx] + L[idx];
        else if (T[idx] >= begin){
            begin = T[idx] + L[idx];
        } else if (T[idx] < begin && T[idx] + D[idx] >= begin) {
            begin += L[idx];
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> T[i] >> D[i] >> L[i];
    }
    int arr[n];
    for (int i = 0; i < n; i ++) {
        arr[i] = i;
    }   
    do {
        if (check(n, arr)) {
            puts("YES");
            goto outSide;
        }
    } while (next_permutation(arr, arr + n));
    puts("NO");
    outSide:
}

int main(void) {    
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin >> t;

    for (int i = 0; i < t; i ++) {
        solve();
    }
    return 0;
}