#include <iostream>

using namespace std;

const int N = 31 * 10e5;
int num[N][2], idx;

void insert(int n) {
    int p = 0;
    for (int i = 30; ~i; i --) {
        int& s = num[p][n >> i & 1];
        s = s ? s : ++idx;
        p = s;
    }
}

int query(int n) {
    int p = 0, res = 0;
    for (int i = 30; ~i; i --) {
        int s = n >> i & 1;
        if (num[p][!s]) {
            res += 1 << i;
            p = num[p][!s];
        } else {
            p = num[p][s];
        }
    }
    return res;
}

int main(void) {
    int n, i, maxNum = 0, res = 0;
    cin >> n;
    int tmpN[n];
    
    for (int i = 0; i < n; i ++) {
        cin >> tmpN[i];
        insert(tmpN[i]);
    }
    
    for (int i = 0; i < n; i ++) {
        res = max(res, query(tmpN[i]));
    }


    printf("%d", res);
    return 0;
}
