#include <iostream>
#include <set>

const int N = 2e5 + 10;

using namespace std;

int t, n, k, h[N], p[N];
set<pair<int, int>> s_h, s_p;

int main(void) {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t --) {
        s_h.clear();
        s_p.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i ++) cin >> h[i]; 
        for (int i = 0; i < n; i ++) {
            cin >> p[i];
            s_h.insert({h[i], p[i]});
            s_p.insert({p[i], h[i]});
        }
        int x = 0;
        while (!s_h.empty() && k > 0) {
            x += k;
            while (!s_h.empty() && (*s_h.begin()).first <= x) {
                int l = (*s_h.begin()).first;
                int r = (*s_h.begin()).second;
                s_h.erase(s_h.begin());
                s_p.erase(s_p.find({r, l}));
            }
            k -= (*s_p.begin()).first;
        }
        if (s_h.empty()) puts("YES");
        else puts("NO");
        /* code */
    }
    

    return 0;
}