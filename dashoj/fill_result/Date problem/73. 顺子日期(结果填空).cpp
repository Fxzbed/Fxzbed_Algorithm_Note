#include <bits/stdc++.h>

using namespace std;
int ans;

int main(void) {
    for (int m = 1; m <= 12; m ++) {
        for (int d = 1; d <= 31; d ++) {
            char s[8];
            if (m == 2 && d == 29) {
                break;
            }

            if (m == 4 || m == 6 || m == 9 || m == 11) 
                if (d == 31) break;

            sprintf(s, "2022%02d%02d", m, d);
            for (int i = 0; i < 6; i ++) {
                if (s[i + 2] - s[i + 1] == 1 && s[i + 1] - s[i] == 1) {
                    ans ++;
                    break;  //一个日期只有一次
                }
            }
        }  
    }

    cout << ans;

    return 0;
}