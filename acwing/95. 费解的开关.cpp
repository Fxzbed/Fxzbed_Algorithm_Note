#include <iostream>
#include <cstring>

using namespace std;

char str[10][10];

const int dx[5] = {1, 0, -1, 0, 0};
const int dy[5] = {0, -1, 0, 1, 0};

void turn(int x, int y) {
    for (int i = 0; i < 5; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < 5 && b >= 0 && b < 5)
            str[a][b] = str[a][b] == '0' ? '1' : '0';
    }
}

void findMinStep() {
    int res = 1000000;
    for (int k = 0; k < 32; k ++) {
        bool ist = true;
        int res_ = 0;
        char backup[10][10];
        memcpy(backup, str, sizeof str);        
        for (int i = 0; i < 5; i ++) {
            if (k >> i & 1) {
                turn(0, i); 
                res_ ++;
            }
        }

        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 5; j ++) {
                if (str[i][j] == '0') {
                    turn(i + 1, j);
                    res_ ++;
                }
            }
        }

        for (int i = 0; i < 5; i ++) {
            if (str[4][i] == '0') {
                ist = false;
                break;
            }
        }

        if (ist) res = min(res, res_);
        memcpy(str, backup, sizeof backup);
    }
    if (res > 6) 
        cout << -1 << endl;
    else 
        cout << res << endl;
}

int main(void) {
    int n;
    cin >> n;

    while (n --) {
        for (int i = 0; i < 5; i ++) scanf("%s", str[i]);
        findMinStep();
    } 

    return 0;
}