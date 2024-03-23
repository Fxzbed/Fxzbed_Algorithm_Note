#include <iostream> 

using namespace std;

const int N = 2e5 + 10;

int n, a[N];

long long merge_sort(int l, int r) {
    if (l >= r) 
        return 0;
    int len = 0;
    int mid = l + r >> 1;
    long long res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int tmp[r - l + 1], lptr = l, rptr = mid + 1;
    while (lptr != mid + 1 && rptr <= r) {
        if (a[lptr] <= a[rptr]) {
            tmp[len ++] = a[lptr ++];
        } else if (a[lptr] > a[rptr]) {
            res += mid - lptr + 1;
            tmp[len ++] = a[rptr++];
        } 
    }
    while (lptr != mid + 1) tmp[len ++] = a[lptr ++];
    while (rptr <= r) tmp[len ++] = a[rptr ++];
    for (int i = l, k = 0; i <= r; i ++) a[i] = tmp[k ++];
    return res;
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    cout << merge_sort(0, n - 1) << endl;
    return 0;
}