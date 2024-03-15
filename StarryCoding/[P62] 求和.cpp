#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

//StarryCoding int最大正整数大概取到5e5  数组都开long long
const int N = 1e5 + 10;
long long a[N], n, l[N], r[N], res;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    
    stack<int> st;

    for (int i = 1; i <= n; i ++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) l[i] = 0;
        else l[i] = st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();

    for (int i = n; i >= 1; i --) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) r[i] = n + 1;
        else r[i] = st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; i ++) {
        res += a[i] * (i - l[i]) * (r[i] - i);
    }

    cout << res << endl;
}


/*
#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;

long long res;
int a[N], n;
stack<int> l, r;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i ++) {
        int ptr = i, left = 1, right = 1;
        while (ptr > 0 && a[i] < a[--ptr]) left ++;
        ptr = i;
        while (ptr < n - 1 && a[i] <= a[++ptr]) right ++;
        res += (left * right) * a[i];
    }

    cout << res << endl;
}*/

// #include <iostream>
// #include <stack>
// #define endl '\n'
// using namespace std;

// const int N = 1e5 + 10;

// long long res;
// int a[N], n, l[N], r[N];

// int main(void) {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i ++) {
//         cin >> a[i];
//     }
    
//     stack<int> st;

//     for (int i = 1; i <= n; i ++) {
//         while (!st.empty() && a[st.top()] >= a[i]) st.pop();
//         if (st.empty()) l[i] = 0;
//         else l[i] = st.top();
//         st.push(i);
//     }
    
//     while (!st.empty()) st.pop();

//     for (int i = n; i >= 1; i --) {
//         while (!st.empty() && a[st.top()] > a[i]) st.pop();
//         if (st.empty()) r[i] = n + 1;
//         else r[i] = st.top();
//         st.push(i);
//     }

//     for (int i = 1; i <= n; i ++) {
//         res += a[i] * (i - l[i]) * (r[i] - i);
//     }

//     cout << res << endl;
// }

/*
#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;

long long res;
int a[N], n;
stack<int> l, r;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i ++) {
        int ptr = i, left = 1, right = 1;
        while (ptr > 0 && a[i] < a[--ptr]) left ++;
        ptr = i;
        while (ptr < n - 1 && a[i] <= a[++ptr]) right ++;
        res += (left * right) * a[i];
    }

    cout << res << endl;
}*/