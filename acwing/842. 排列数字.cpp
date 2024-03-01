#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N =  1e5;
int n;
int path[N];
bool isT[N];

void dfs(int u) {
    if (u == n) {
        //走到了头
        for (int i = 0; i < n; i ++) printf("%d ", path[i]);
        putchar('\n');
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (!isT[i]) {  //没走过    
            path[u] = i + 1;
            isT[i] = true;
            dfs(u + 1);
            isT[i] = false;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    dfs(0);
    return 0;
}

/*
    Go version

    package main

    import "fmt"

    const N int = 1e5

    var n int

    var path [N]int
    var isT [N]bool

    func dfs(u int) {
        if u == n {
            for i := 0; i < n; i += 1{
                fmt.Print(path[i], " ")
            }
            fmt.Print("\n")
            return
        }

        for i := 0; i < n; i += 1 {
            if !isT[i] {
                path[u] = i + 1
                isT[i] = true
                dfs(u + 1)
                isT[i] = false
            }
        }
        return
    }

    func main() {
        fmt.Scan(&n)
    // 	fmt.Print(n)
        dfs(0)
        return
    }
*/