#include<iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int t, n, k, a[100010], b[100010], vis[100010];

auto cmp = [](int x, int y) {return a[x] < a[y];};

int main() { 
    memset(vis, -1, sizeof vis);
    cin >> t; 
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) b[i] = i; 
        
        int l = 1, r = n;
        sort(b + 1, b + n + 1, cmp); 
        int res = n, las = 0;
        for(int i = 1; i <= n;){
            for(int j = las + 1; j < a[b[i]]; j++) cout << 0 << ' ';
            cout << res * 2 << ' '; int p = i; vis[b[p]] = t;
            while(a[b[p]] == a[b[i]]) vis[b[p++]] = t; 
            las = a[b[i]];
            for(l = l; l <= r;) {
                if(vis[l] != t) break; 
                l++;
                res--;
            }
            for(r = r; r >= l;) {
                if(vis[r] != t) break; 
                r--;
                res--;
            } 
            i = p;
        } 
        for(int i = las + 1; i <= k; i++) cout << 0 << ' '; 
        cout << '\n';
    }
}