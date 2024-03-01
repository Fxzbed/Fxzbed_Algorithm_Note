#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2 * 1e5 + 10;
int n, d, k, j, l;
vector<pair<int, int>>a;
vector<int> res;
int ts[N];
bool ist[N];

int main() {
    cin >> n >> d >> k;
    int t, t_;
    for (int i = 0; i < n; i ++) {
        cin >> t >> t_;
        a.push_back({t, t_});
    }

    sort(a.begin(), a.end());

    for (int i = 0, j = 0; i < n; i ++) {
        int id = a[i].second;
        ts[id] ++;
        while (a[i].first - a[j].first >= d) {
            ts[a[j].second] --;
            j ++;
        }
        if (ts[id] >= k && !ist[id]) {res.push_back(id); ist[id] = true;}
    }
    sort(res.begin(), res.end());
    for (auto& x : res) cout << x << endl;
    return 0;
}