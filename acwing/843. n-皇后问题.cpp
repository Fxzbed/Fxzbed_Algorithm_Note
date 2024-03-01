#include <iostream>

using namespace std;

constexpr int N = 20;

char path[N][N];
bool col[N], dg[N], udg[N];
int n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) puts(path[i]);
        putchar('\n');
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            path[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            path[u][i] = '.';
        }
    }
}

int main(void) {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++) 
        for (int x = 0; x < n; x ++) 
            path[i][x] = '.';
    dfs(0);
    return 0;
}

/*
    go version
    package main

    import "fmt"

    const N int = 20

    var (
        path [N][N]rune
        col [N]bool
        dg [N]bool 
        udg [N]bool
        n int
    )

    func dfs(u int) {
        if u == n {
            for i := 0; i < n; i += 1 {
                for x := 0; x < n; x += 1 {
                    fmt.Print(string (path[i][x]))
                }
                fmt.Print("\n")
            }
            fmt.Print("\n")
            return
        }
        
        for i := 0; i < n; i += 1 {
            if !col[i] && !dg[i + u] && !udg[n - u + i] {
                path[u][i] = 'Q'
                col[i], dg[i + u], udg[n - u + i] = true, true, true
                dfs(u + 1)
                col[i], dg[i + u], udg[n - u + i] = false, false, false
                path[u][i] = '.'
            }
        }
    }

    func main() {
        fmt.Scanln(&n)
        for i := 0; i < n; i += 1 {
            for x := 0; x < n; x += 1 {
                path[i][x] = '.'
            }
        }
        dfs(0)
    }
*/