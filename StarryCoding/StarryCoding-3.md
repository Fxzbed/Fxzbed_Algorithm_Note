## *StarryCoding Algorithm Note - 3 栈、优先队列、map、set、bitset*

### *bitset 与 存在性dp （题例）*

**[P39] 数的种类** - https://www.starrycoding.com/problem/39

![StarryCoding Algorithm](/Users/fxzbed/Downloads/StarryCoding Algorithm.jpeg)

二维存在性dp，如下

```c++
#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int n, a[N];
bool dp[N][N];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= 5e3; j ++) {
            dp[i][j] = dp[i - 1][j];    //拿回上一次的结果
            if (j >= a[i]) {
                dp[i][j] |= dp[i - 1][j - a[i]];    //在上一次能够组成 j-a[i] 的值，此时到达第a[i]，可以为上一次能组成的数都加上a[i]，所以选择 j-a[i]
            }
        }
    }
    long long res = 0;
    for (int i = 0; i <= 5e3; i ++) {
        res += dp[n][i];
    }
    cout << res << endl;
    return 0;
}

```

对于每次的拷贝，压缩为一维，即每次的操作都在原数组中完成。可以写成

```c++
#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int n, a[N];
bool dp[N];
long long res;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= N; i ++) {
        for (int j = N; j >= a[i]; j --) {
            dp[j] |= dp[j - a[i]];
        }
    }

    for (int i = 0; i <= N; i ++) 
        if (dp[i]) res ++;
    
    cout << res << '\n';
    return 0;
}
```

注意到上述的数据都为存在性，想到位图bitset

正解：

```c++
#include <iostream>
#include <bitset>

using namespace std;

const int N = 5e5 + 10;

int n;
bitset<N> bs;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    bs[0] = 1;
    while (n --) {
        int t; cin >> t;
        bs |= (bs << t);
    }

    cout << bs.count() << '\n';

    return 0;
}
```

![StarryCoding Algorithm 2](/Users/fxzbed/Downloads/StarryCoding Algorithm 2.jpeg)

---

### *priority_queue*

优先队列，使用堆排序构成的一个队列

默认堆顶为最大，从大到小排序。

重载priority_queue的方法：

```c++
#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> q;

int t[5];

struct node {
    int val;
    bool operator <(const node &b) const{
        return val > b.val;
    }
    node(int n): val(n) {};
};

struct cmp {
    bool operator ()(const int &a, const int &b) const {
        return a > b;
    }
};

int main(void) {
    int n; cin >> n;
    for (int i = 0; i < 5; i ++) {
        cin >> t[i];
        q.push(t[i]);
    }
    cout << "priority_queue:" << '\n';
    for (int i = 0; i < n; i ++) {
        cout << q.top() << ' ';
        q.pop();
    }
    puts("");

    priority_queue<node, vector<node>> q_;

    cout << "node operate < priority_queue:" << '\n';

    for (auto x : t) {
        q_.push(node(x));
    }
    while (!q_.empty()) {
        cout << q_.top().val << ' ';
        q_.pop();
    }
    puts("");

    cout << "cmp operate () priority_queue:" << '\n';

    priority_queue<int, vector<int>, cmp> q__; 

    for (auto x : t) {
        q__.push(x);
    }
    while (!q__.empty()) {
        cout << q__.top() << ' ';
        q__.pop();
    }
    puts("");

    return 0;
}
```

![image-20240314181523233](/Users/fxzbed/Library/Application Support/typora-user-images/image-20240314181523233.png)

