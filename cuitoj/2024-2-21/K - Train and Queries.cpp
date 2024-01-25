#include <iostream>
#include <map>

const int N = 2e5 + 10;

using namespace std;

int t, n ,k;

int main(void) {
    cin >> t;
    while (t --) {
        map<int, int> m_l, m_r;
        cin >> n >> k;
        int tmp;
        for (int i = 0; i < n; i ++) {
            cin >> tmp;
            if (m_l.find(tmp) == m_l.end() || m_l[tmp] > i) 
                m_l[tmp] = i;
            if (m_r.find(tmp) == m_r.end() || m_r[tmp] < i)
                m_r[tmp] = i;
        }
        int q1, q2;
        for (int i = 0; i < k; i ++) {
            cin >> q1 >> q2;
            if (m_l.find(q1) != m_l.end() && m_r.find(q2) != m_r.end() && m_l[q1] <= m_r[q2])
                puts("YES");
            else 
                puts("NO");
        }

    }
    return 0;
}