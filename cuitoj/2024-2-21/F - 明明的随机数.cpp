#include <iostream>
#include <algorithm>

const int N = 1e2 + 10;

using namespace std;

int n, cnt;
int nums[N], numMap[1010];

int main(void) {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i ++) {
        cin >> tmp;
        if (numMap[tmp] == 0) {
            numMap[tmp] = 1;
            nums[cnt++] = tmp;
        }
    }

    sort(nums, nums + cnt);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i ++) cout << nums[i] << ' ';

    return 0;
}