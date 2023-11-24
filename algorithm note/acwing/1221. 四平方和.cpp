#include <iostream>
#include <cmath>

using namespace std;

const int N = 5e6 + 10;
int m[N * 2], n;

int main(void) {
    cin >> n;
    
    memset(m, -1, sizeof m);
    
    for (int c = 0; c * c <= n; c ++) {
        for (int d = c; c * c + d * d <= n; d ++) {
            int t = c * c + d * d;
            if (m[t] == -1)
                m[t] = c;
        }
    }
    
    for (int a = 0; a * a <= n; a ++) {
        for (int b = a; a * a + b * b <= n; b ++) {
            if (m[n - (a * a + b * b)] != -1) {
                int c = m[n - (a * a + b * b)];
                int d = sqrt(n - a * a - b * b - c * c);
                cout << a << ' ' << b << ' ' << c << ' ' << d;
                return 0;
            }
        }
    }
    
    return 0;
}