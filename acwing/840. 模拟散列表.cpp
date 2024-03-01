#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 3;

int head[N], ptr[N], num[N], idx = 1;

void insert(int x) {
    int k = (x % N + N) % N;
    
    num[idx] = x;
    ptr[idx] = head[k]; 
    head[k] = idx ++;
}

bool query(int x) {
    for (int i = head[(x % N + N) % N]; i != 0; i = ptr[i]) 
        if (num[i] == x) 
            return true;
            
    return false;
}
int main(void) {
    char opt[2];
    int n, x;
    
    scanf("%d", &n);
    while (n --) {
        scanf("%s%d", opt, &x);
        if (opt[0] == 'I') insert(x);
        else if (query(x)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}
