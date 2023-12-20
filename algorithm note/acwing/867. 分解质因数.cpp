#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, a[N];

void dividesPrime(int& a) {
    for (int i = 2; i <= a / i; i ++) {
        if (a % i == 0) {
            int s = 0;
            while (a % i == 0) {
                a /= i;
                s ++; 
            }
            cout << i << ' ' << s << endl;
        }
    }
    if (a > 1) cout << a << ' ' << 1 << endl;
    puts("");
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        dividesPrime(a[i]);
    }


    return 0;
}