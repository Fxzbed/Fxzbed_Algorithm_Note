#include <iostream>
#include <stack>

using namespace std;

const int N = 2e5 + 10;

int n;
stack<int> st;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        while (!st.empty() && st.top() >= tmp) st.pop();
        if (st.empty()) {
            cout << "-1" << ' ';
        } else if (st.top() < tmp) {
            cout << st.top() << ' ';
        }
        st.push(tmp);
    }
    return 0;
}