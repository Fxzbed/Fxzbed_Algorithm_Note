#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 110;

int map[N][N];
int d[N][N];
pair<int, int> q[N * N];
int hh, tt;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;

int bfs() {
    q[0] = {0, 0};
    // memset(d, -1, sizeof d);

    while (hh <= tt) {
        auto t = q[hh ++];
        for (int i = 0; i < 4; i ++) {
            int x_ = dx[i] + t.first;
            int y_ = dy[i] + t.second;
            if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < m && d[x_][y_] == 0 && map[x_][y_] == 0) {
                d[x_][y_] = d[t.first][t.second] + 1;
                q[++ tt] = {x_, y_};
            }
        }
    }

    return d[n - 1][m - 1];
}

int main(void) {
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++) 
        for (int x = 0; x < m; x ++)
            scanf("%d", &map[i][x]);
            
    cout << bfs() << endl;
    return 0;
}

/*  
//go version
package main

import (
    "fmt"
)

const N = 110

var (
    map_ [N][N]int
    d [N][N]int
    q [N * N]pair
    hh, tt int
    dx = [4]int{1, 0, -1, 0}
    dy = [4]int{0, 1, 0, -1}
    n, m int
)

type pair struct {
    first int
    second int
}

func bfs() int {
    q[0] = pair{0, 0}
    // memset(d, -1, sizeof d);

    for hh <= tt {
        t := q[hh]
        hh ++
        for i := 0; i < 4; i ++ {
            x_ := dx[i] + t.first
            y_ := dy[i] + t.second
            if x_ >= 0 && y_ >= 0 && x_ < n && y_ < m && d[x_][y_] == 0 && map_[x_][y_] == 0 {
                d[x_][y_] = d[t.first][t.second] + 1
                q[tt + 1] = pair{x_, y_}
                tt ++
            }
        }
    }

    return d[n - 1][m - 1]
}

func main() {
    fmt.Scan(&n, &m)
    
    for i := 0; i < n; i ++ {
        for x := 0; x < m; x ++ {
            fmt.Scan(&map_[i][x])
        }
    }
            
    fmt.Println(bfs())
}
*/