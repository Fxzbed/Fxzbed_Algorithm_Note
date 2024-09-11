<h1 style="text-align: center;"><i>StarryCoding</i></h1>

#### *PrefixSum*

##### *Principle explanation*

To find the sum of a continuous sequence of elements in an array, we use algorithm called ==PrefixSum==. When we have an array named "$a$", you need to output the sum of elements in array "a" from index "l" to index "r"

We create an array named "$PrefixSumArray$". Every elements in   $PrefixSumArray$ is the sum of  the elements before its own index. 

$PrefixSum$ will be like:

```c++
void PrefixSum() {
  for (int i = 1; i < n; i ++) {
		PrefixSumArray[i] += PrefixSumArray[i - 1];      
  }
}
```

With the $PrefixSumArray$, we can calculate sum of elements in "$a$" from index 'l' to index 'r' by $PrefixSumArray[r] - PrefixSumArray[l - 1]$

##### *Template Code - PrefixSum:*

[*P7 【模板】前缀和*](https://www.starrycoding.com/problem/7)

```c++
#include <iostream>

const int N = 1e5 + 10;

int T, n, q;
long long a[N];

using namespace std;

void prefixSum() {
    for (int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
    }
}

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> q;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }

        prefixSum();

        for (int j = 0; j < q; j++) {
            int l, r;
            cin >> l >> r;
            cout << a[r] - a[l - 1] << endl; 
        }
    }
    return 0;
}
```

[*P15 【模板】二维前缀和*](https://www.starrycoding.com/problem/15)

```c++
#include <iostream>

const int N = 1e3 + 10;

using namespace std;

int n, m, q, a[N][N];
long long prefix[N][N];

inline void prefixSum2D() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    prefixSum2D();

    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}
```

---

#### *Difference*

##### *Principle explanation*

Difference and PrefixSum are very similar. When you want to add "x" continuously in array "a" from index "l" to index "r", you need to diff this array.

Similar to PrefixSum, we create a array "$diff$" each elements is the difference between the same index in "a" and the previous element in "a" 

$Difference$ will be like

```c++
void difference() {
    for (int i = 1; i <= n; i ++) {
        diff[i] = a[i] - a[i - 1];
    }
}
```

With array "$diff$", you can add a num in batch from index "l" to "r" by plus "x" to $diff[l]$  and sub $diff[r + 1]$

##### *Template Code - Difference:*

[*P8 【模板】差分*](https://www.starrycoding.com/problem/8)

```c++
#include <iostream>

const int N = 1e5 + 10;

int n, p, q;
long long prefix[N], diff[N], a[N];

using namespace std;

void difference() {
    for (int i = 1; i <= n; i ++) {
        diff[i] = a[i] - a[i - 1];
    }
}

void prefixSum() {
    for (int i = 1; i <= n; i ++) {
        a[i] = diff[i] + a[i - 1];
        prefix[i] = a[i] + prefix[i - 1];
    }
}

int main (void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    difference();

    for (int i = 0; i < p; i ++) {
        int l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }

    prefixSum();

    for (int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}
```

==Difference in 2D==

The principle of Diff in 2D is hard to explain. So we assume there is an array all elements are 0. We construct original array by differencing this array. 

difference array will be constructed like this:

``` 
a[i][j] = x; //assume a[i][j] is x

diff[i][j] += x;
diff[i][j + 1] -= x;
diff[i + 1][j] -= x;
diff[i + 1][j + 1] += x;
```

[*P50 【模板】二维差分*](https://www.starrycoding.com/problem/50)

```c++
#include <iostream>

const int N = 1e3 + 10;

using namespace std;

int n, m, q;
long long a[N][N], prefix[N][N], diff[N][N];

void difference2D() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            diff[i][j] += a[i][j];
            diff[i + 1][j] -= a[i][j];
            diff[i][j + 1] -= a[i][j];
            diff[i + 1][j + 1] += a[i][j]; 
        }
    }
}

void prefixSum2D() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            prefix[i][j] = diff[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    difference2D();

    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        diff[x1][y1] += c;
        diff[x2 + 1][y1] -= c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y2 + 1] += c;  
    }

    prefixSum2D();

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << prefix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
```

---

#### *Practice Question*

##### [*P35 鼠鼠我鸭*](https://www.starrycoding.com/problem/35)

```c++
#include <iostream>

const int N = 1e5 + 10;

using namespace std;

int T, n, a[N];
bool isMorD[N];
long long prefix[N], minPrefix[N], ess, ans;

void prefixSum() {
    for (int i = 1; i <= n; i ++ ) {
        prefix[i] = a[i] + prefix[i - 1];
        minPrefix[i] = min(minPrefix[i - 1], prefix[i]);
    }
}

int main(void) {
    ess = 0;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T --) {
        ess = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> isMorD[i];
        }

        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            if (isMorD[i]) {
                ess += a[i];
                a[i] *= -1;
            }
        }

        ans = ess;
        prefixSum();

        for (int i = 1; i <= n; i ++) {
            ans = max(ans, ess + prefix[i] - minPrefix[i - 1]);
        }

        cout << ans << endl;
    }
    return 0;
}
```





