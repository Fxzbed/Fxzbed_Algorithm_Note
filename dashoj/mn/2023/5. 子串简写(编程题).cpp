#include <bits/stdc++.h>

using namespace std;

int k;
long long ans;
string s;
char front, back;
vector<int> f, b;

int binary_search(int l, int r, int t) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (b[mid] > t) {
            r = mid;
        } else if (b[mid] < t) {
            l = mid + 1; 
        } else if (b[mid] == t) return mid;
    }
    return l;
}

int main(void) {
    cin >> k >> s >> front >> back;
    for (int i = 0; i < (int)s.size(); i ++) {
        if (s[i] == front) f.push_back(i);
        else if (s[i] == back) b.push_back(i);
    }
    
    auto bs = b.size();

    for (int i = 0; i < (int)f.size(); i ++) {
        int idx = binary_search(0, b.size(), f[i] + k - 1);
        if (idx < (int)b.size()) ans += (int)bs - idx;
    }

    cout << ans;
    return 0;
}