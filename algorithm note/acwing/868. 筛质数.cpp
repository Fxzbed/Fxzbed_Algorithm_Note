#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], n, res;
bool ist[N];

int main(void) {
    cin >> n;
    for (int i = 2; i <= n / i; i ++) {
        if (!ist[i]) 
            for (int j = i * i; j <= n; j += i) 
                ist[j] = true;
    }

    for (int i = 2; i <= n; i ++) if (!ist[i]) res ++;
    cout << res;
    return 0;
}

//埃氏筛法