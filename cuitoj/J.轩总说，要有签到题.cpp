#include <iostream>

using namespace std;

const int N = 1e6 + 10;
char c[N];
int c_[26];
int c__[26];

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
        c_[c[i] - 'A'] ++;
    }

    for (int i = 0; i < n; i ++) {
        cin >> c[i];
        c__[c[i] - 'A'] ++;
    }
    
    for (int i = 0; i < 26; i ++) {
        if (c__[i] != c_[i]) {cout << "klyyds"; return;}
    }

    cout << "kldrgonyyds";
    return 0;
}