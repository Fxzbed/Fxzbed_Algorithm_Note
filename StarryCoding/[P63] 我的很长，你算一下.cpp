#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 10;

int n, q;
pair<long long, long long> add[N];
pair<long long, long long> query[N];
vector<long long> X;
long long value[N];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        long long idx, x;
        cin >> idx >> x;
        add[i] = {idx, x};
        X.push_back(idx);
    }

    for (int i = 1; i <= q; i ++) {
        long long l, r;
        cin >> l >> r;
        query[i] = {l, r};
        X.push_back(l);
        X.push_back(r);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    auto getid = [&](long long u) -> long long{
        return lower_bound(X.begin(), X.end(), u) - X.begin() + 1;
    };  //二分映射

    for (int i = 1; i <= n; i ++) {
        int x = getid(add[i].first);
        long long w = add[i].second;
        value[x] += w;
    }

    for (int i = 1; i <= X.size(); i ++) {
        value[i] += value[i - 1];
    }

    for (int i = 1; i <= q; i ++) {
        cout << value[getid(query[i].second)] - value[getid(query[i].first) - 1] << '\n';
    }

    return 0; 
}

//离散化映射数组，值域小而下标大的情况