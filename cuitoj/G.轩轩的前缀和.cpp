#include <iostream>

using namespace std;

const int N = 5 * 1e5 + 10;
int n, k;
int an[N];

int main(void) {
    cin >> n >> k;
    int o1, o2, x;
    cin >> o1 >> o2 >> x;
    an[o1] += x;
    an[o2 + 1] += -x; 
    // cout << an[o2 + 1];
    for (int i = 1; i < k; i ++) {
        an[o1] += an[o1];
        an[o2 + 1] += an[o2 + 1];
        // cout << o2 + 1  << ':' << an[o2 + 1] << ' ' << o1 << ':' << an[o1] << endl; 
        cin >> o1 >> o2 >> x;
        an[o1] += x;
        an[o2 + 1] -= x;
    }

    int tmp = 0;
    for (int i = 1; i <= n; i ++) {
        tmp += an[i];
        cout << tmp << ' ';
    }
    return 0;
}