#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
constexpr int N = 1e5 + 10;

int res = N;
int n;
int h[N], e[N * 2], ne[N * 2], idx;
bool ist[N];

void insert(int a, int b) {
    //insert a -> b
    e[idx] = b;
    ne[idx] = h[a]; 
    h[a] = idx ++;
}



int dfs(int u) {
    ist[u] = true;
    
    int sum = 1, size = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        if (!ist[e[i]]) {
            int s = dfs(e[i]);
            size = max(s, size);
            sum += s;
        }      
    }
    res = min(max(size, n - sum), res);
    return sum;
}

int main(void) {

    scanf("%d", &n);
    memset(h, -1, sizeof h);
    
    int x = n;
    while (x --) {
        int a, b;
        cin >> a >> b;
        insert(a, b);
        insert(b, a);
    }
    
    dfs(1);
    cout << res << endl;
    
    return 0;
}