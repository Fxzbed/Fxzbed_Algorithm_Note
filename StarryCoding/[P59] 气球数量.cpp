#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

int n, t, len;
vector<pair<string, int>> s;
map<string, int> ist;

int main(void) {
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            char t_s[51];
            cin >> t_s;
            if (ist.find(t_s) == ist.end()) {
                ist[t_s] = len ++;
                s.push_back({t_s, 0});
            }
            s[ist[t_s]].second ++;
        }

        for (auto x : s) {
            cout << x.first << ' ' << x.second << '\n';
        }

        ist.clear();
        s.clear();
        len = 0;
    }
    return 0;
}