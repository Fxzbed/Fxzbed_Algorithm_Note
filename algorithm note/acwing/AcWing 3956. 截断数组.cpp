#include<iostream>

using namespace std;

const int N = 1e5 + 10;
long long an[N], a[N], n, sum, res;
int main(void) {
    cin >> n;
    
    if (n == 0) return 0;
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        an[i] = an[i - 1]  + a[i];
    }
    
    sum = an[n];
    if (sum % 3) {
        cout << "0" << endl;
        return 0;
    }
    
    int average = sum / 3;
    
    for (int i = 1, cnt = 0; i <= n - 2; i ++) {
        if (an[i] == average) cnt ++;
        if (an[n] - an[i + 1] == average) res += cnt;
        
    }
    
    cout << res << endl;
    return 0;
}