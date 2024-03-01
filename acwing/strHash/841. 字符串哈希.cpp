#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int N = 1e5 + 10, P = 131;

int n, m;
int h[N], p[N];

int main(void) {
    cin >> n >> m;
    string str;
    cin >> str;
    
    h[0] = str[0];
    p[0] = 1;
    for (int i = 1; i < n; i ++) {
        p[i] = p[i - 1] * P;
        h[i] = (h[i - 1] * P + str[i]);
    }
    
    for (int i = 0; i < m; i ++) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (h[r1 - 1] - h[l1 - 2] * p[r1 - l1 + 1] == (h[r2 - 1] - h[l2 - 2] * p[r2 - l2 + 1]))
            puts("Yes");
        else 
            puts("No");
    }
    return 0;
}