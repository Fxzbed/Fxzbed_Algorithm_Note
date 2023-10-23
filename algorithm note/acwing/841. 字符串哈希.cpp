#include <iostream>
#include <cmath>

using namespace std;

constexpr int p = 131;
constexpr int N = 1e5;
 
uint64_t h[N], t[N];
char s[N];
int l ,r, l1, r1;

int main(void) {
    int n, m;
    scanf("%d%d%s", &n, &m, s + 1);

    t[0] = 1;
    for (int i = 1; i <= n; i ++) {
        t[i] = t[i - 1] * p;
        h[i] = h[i - 1] * p + s[i]; //不能使用后缀 ac000 与 ac 后缀和冲突
    }

    while (m --) {
        scanf("%d%d%d%d", &l, &r, &l1, &r1);
        if (h[r] - h[l - 1] * t[r - l + 1] == h[r1] - h[l1 - 1] * t[r1 - l1 + 1]) puts("Yes");
        else puts("No");
    }

    return 0;
}