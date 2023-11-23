#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], h[N], idx, n, head;

int main(void) {
    idx++;
    cin >> n;
    char o;
    int t, t1;
    for (int i = 0; i < n; i ++) {
        cin >> o >> t;
        // cout << o;
        if (o == 'H') {
            e[idx] = t;
            ne[idx] = head;
            head = idx ++;
        } else if (o == 'I') {
            cin >> t1;
            e[idx] = t1;
            ne[idx] = ne[t];
            ne[t] = idx ++;
        }else if (o == 'D') {
            if (t == 0) head = ne[head];
            else ne[t] = ne[ne[t]];
        }
    }
    
    int a = head;

    while (e[a] != 0) {
        cout << e[a] << ' ';
        a = ne[a];
    }
    return 0;
}