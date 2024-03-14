#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n;
deque<int> q;
deque<int> q_o;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int t; cin >> t;
        q.push_back(t);
    }

    q_o.push_back(q.front());
    q.pop_front();
    
    for (int i = 1; i <= n; i ++) {
        while (q_o.front() != i && !q.empty()) {
            q_o.push_front(q.front());
            q.pop_front();
        }
        if (q_o.front() == i)
            q_o.pop_front();
    }

    if (q_o.empty()) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}