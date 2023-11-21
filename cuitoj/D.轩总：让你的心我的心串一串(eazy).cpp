#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n, k;
char c[N];
bool ist;

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> c[i];
    
    for (int i = n / k; i >= 1; i --) {
        for (int j = 0; j <= n - (i * k); j ++) {
            for (int x = j; x < i * k + j; x += i) {
                // cout << i << ':' << x << endl; 
                int count = 1;
                char c_ = c[x];
                for (int z = 1; z <= i - 1; z ++) {
                    // cout << z << ' ' << c[x + z] << endl; 
                    if (c_ != c[x + z]) {
                        ist = true;
                        break;
                    }
                }
            }
            if (!ist) {
                cout << i * k;
                return 0;
            } 
            ist = false;
        }
    }
    return 0;
}