 #include <bits/stdc++.h>
  using namespace std;
 
  int n = 3, m = 4, Map[3][4], Ans;
  int a[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
  int u[4] = {-1, 0, 0, 1},
      v[4] = {0, -1, 1, 0};
  
  void dfs(int x, int y) {
    Map[x][y] = 0;
     for(int i=0; i<4; ++i) {
         int xx = x + u[i];
         int yy = y + v[i];
         if(xx>=0 && xx<3 && yy>=0 && yy<4 && Map[xx][yy]==1)
             dfs(xx, yy);
     }
      }
 
 bool check() {
    for(int i=0; i<3; ++i)
        for(int j=0; j<4; ++j)
            Map[i][j] = a[4*i+j];
     int cnt = 0;
     for(int i=0; i<3; ++i)
         for(int j=0; j<4; ++j) {
             if(Map[i][j] == 1) {
                 dfs(i, j);
                cnt++;
            }
         }
     if(cnt == 1) return true;
     return false;
 }
 
 void work() { 
     do {
         if(check()) Ans++;
     }while(next_permutation(a, a+12));
 }
 
 int main() {
    
     work();
     printf("%d\n", Ans);
     
     return 0;
 }
