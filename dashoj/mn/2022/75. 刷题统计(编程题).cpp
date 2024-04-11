#include <bits/stdc++.h>

using namespace std;

long long first, second, n;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> first >> second >> n;
    long long week = first * 5 + second * 2;
    long long num_1 = n / week;
    long long num_2 = n % week;
    if (num_2) {
        long long sum = 0;
        for (int i = 1; i <= 5; i ++) {
            sum += first;
            if (sum >= num_2) {
                cout << (num_1 * 7) + i << endl;
                return 0;
            }
        }
        
        for (int i = 1; i <= 2; i ++) {
            sum += second;
            if (sum >= num_2) {
                cout << (num_1 * 7) + i + 5 << endl;
                return 0; 
            }
        }
    }
    return 0;
}