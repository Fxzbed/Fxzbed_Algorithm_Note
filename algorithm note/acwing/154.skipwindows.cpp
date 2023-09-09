/*
给定一个大小为 n≤106
 的数组。

有一个大小为 k
 的滑动窗口，它从数组的最左边移动到最右边。

你只能在窗口中看到 k
 个数字。

每次滑动窗口向右移动一个位置。

以下是一个例子：

该数组为 [1 3 -1 -3 5 3 6 7]，k
 为 3
。

窗口位置	最小值	最大值
[1 3 -1] -3 5 3 6 7	-1	3
1 [3 -1 -3] 5 3 6 7	-3	3
1 3 [-1 -3 5] 3 6 7	-3	5
1 3 -1 [-3 5 3] 6 7	-3	5
1 3 -1 -3 [5 3 6] 7	3	6
1 3 -1 -3 5 [3 6 7]	3	7
你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

输入格式
输入包含两行。

第一行包含两个整数 n
 和 k
，分别代表数组长度和滑动窗口的长度。

第二行有 n
 个整数，代表数组的具体数值。

同行数据之间用空格隔开。

输出格式
输出包含两个。

第一行输出，从左至右，每个位置滑动窗口中的最小值。

第二行输出，从左至右，每个位置滑动窗口中的最大值。

输入样例：
8 3
1 3 -1 -3 5 3 6 7
输出样例：
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/

#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
int a[N];

int main(void) {
    int n, k;
    cin >> n >> k;
    deque<int> MonQue;

    for (int i = 1; i <= n; i ++) cin >> a[i];

    // print min
    for (int i = 1; i <= n; i ++) {
        while (MonQue.size() && MonQue.front() > a[i]) {
            MonQue.pop_front();
        }
        MonQue.push_front(a[i]);
        if (i - k >= 1 && a[i - k] == MonQue.back()) {
            MonQue.pop_back();
        } 
        if (i >= k) cout << MonQue.back() << ' ';
    }
    MonQue.clear();
    
    cout << endl;
    for (int i = 1; i <= n; i ++) {
        while (MonQue.size() && MonQue.front() < a[i]) {
            MonQue.pop_front();
        }
        MonQue.push_front(a[i]);
        if (i - k >= 1 && a[i - k] == MonQue.back()) {
            MonQue.pop_back();
        }
        if (i >= k) cout << MonQue.back() << ' ';
    }
    return 0;
}
/*
#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;
int a[N];

int main() {
    // ios::sync_with_stdio(false);
    int n, k;
    deque<int> MonQue;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        while (MonQue.size() && MonQue.back() > a[i]) {
            MonQue.pop_back();
        }
        MonQue.push_back(a[i]);
        if (i - k >= 1 && MonQue.front() == a[i - k]) {
            MonQue.pop_front();
        }
        if (i >= k) {
            cout << MonQue.front() << ' ';
        }
    }
    MonQue.clear();
    cout << endl;
    for (int i = 1; i <= n; i ++) {
        while (MonQue.size() && MonQue.back() < a[i]) {
            MonQue.pop_back();
        }
        MonQue.push_back(a[i]);
        if (i - k >= 1 && MonQue.front() == a[i - k]) {
            MonQue.pop_front();
        }
        if (i >= k) {
            cout << MonQue.front() << ' ';
        }
    }
}*/