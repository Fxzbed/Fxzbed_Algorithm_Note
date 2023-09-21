#include <iostream>

using namespace std;

const int N = 10e5 + 10;

char s1[N], s2[N];
int ne[N];

int main(void) {
    int n, m;

    cin >> n >> s1 + 1 >> m >> s2 + 1;
    //index from 1;

    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && s1[i] != s1[j + 1]) j = ne[j];
        if (s1[i] == s1[j + 1]) j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++) {
        while (j && s2[i] != s1[j + 1]) j = ne[j];
        if (s1[j + 1] == s2[i]) j ++;
        if (j == n) {
            cout << i - j << ' ';
            j = ne[j];
        }
    }

    return 0;
}