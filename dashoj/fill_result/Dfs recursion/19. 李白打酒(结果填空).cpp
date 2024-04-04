// #include <iostream>
// #include <map>

// using namespace std;

// int res = 0;

// void check(int m, int f, int s) {
//     if (m > 5 || f > 9) return;

//     if (m == 5 && f == 9) {
//         if (s == 1) {
//             res ++;
//             return;
//         }
//     }

//     check(m + 1, f, s * 2);
//     check(m, f + 1, s - 1);
// }

// int main(void) {
//     check(0, 0, 2);
//     cout << res;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int l[15], res;
map<string, bool> g;

bool check() {
    if (l[14] != 1) return false;
    int s = 2;
    for (int i = 0; i < 15; i ++) {
        if (l[i] == -1) s *= 2;
        else s --;
    }
    return s == 0;
}

int main(void) {
    for (int i = 0; i < 5; i ++) l[i] = -1; //*2
    for (int i = 5; i < 15; i ++) l[i] = 1; //--

    do {
        if (check()) {
            for (int i = 0; i < 15; i ++) cout << l[i];
            puts("");
            res ++;
        }
    } while (next_permutation(l, l + 15));  //不重复的全排列

    cout << res;
    return 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int a[15]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,2,2,2,2};//-1遇花，2遇店

//     int n = 0;//记录总数
//     do{
//         int sum = 2; //初始斗酒数

//         for(int i=0; i<15; i++){
//             if(a[i] == -1){
//                 sum += a[i];
//             }else{
//                 sum *= a[i];
//             }
//         }

//         if(a[14]==-1&&sum==0){ //a[14]最后一次是遇花
//             n +=1;  
//         }       

//     }while(next_permutation(a,a+15));//全排列

//     cout<< n << endl;
//     return 0;
// } 
