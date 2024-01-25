#include <iostream>
#include <set>

using namespace std;

int q, le, ri;
char op;
multiset<int> l, r;

int main(void) {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q --) {
        cin >> op >> le >> ri;
        if (op == '+') {
            l.insert(le);
            r.insert(ri);
        } else {
            l.erase(l.find(le));
            r.erase(r.find(ri));
        }
        auto it = l.end();
        if (!r.empty() && !l.empty() && *r.begin() < *(--it)) 
            puts("YES");
        else 
            puts("NO");
        /* code */

    }
    
    return 0;
}