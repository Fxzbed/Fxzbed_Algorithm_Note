//试除法
#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, a[N];

bool judgePrime(int& a) {
    if (a < 2) return false;
    for (int i = 2; i <= a / i; i ++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (judgePrime(a[i])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}