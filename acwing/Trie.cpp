#include <iostream>

using namespace std;

const int N = 2 * (10e4) + 10;

int Trie[N][26], cnt[N], idx;

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        char c = str[i] - 'a';
        if (!Trie[p][c]) Trie[p][c] = ++idx;
        p = Trie[p][c];
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        char c = str[i] - 'a';
        if (!Trie[p][c]) return 0;
        p = Trie[p][c];
    }

    return cnt[p];
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t --) {
        char opt[2], str[N];
        scanf("%s%s", opt, str);
        if (opt[0] == 'I') insert(str);
        else cout << query(str) << '\n';
    }   
    return 0;
}