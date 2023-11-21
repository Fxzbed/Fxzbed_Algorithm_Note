#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, tmp, times;
long long a[N];

void sp(int& a, int& b) {

}

int main(void) {
    cin >> n;
    cin >> a[1];
    times = a[1];
    if (n == 1) {
        cout << 0;
        return 0;
    } 

    for (int i = 2; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 1; i --) {
        if (a[i] > a[i + 1]) {
            sp()
        }
    }

    return 0;
}