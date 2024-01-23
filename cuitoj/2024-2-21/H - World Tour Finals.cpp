#include <iostream>
#include <algorithm>

const int N = 120;

using namespace std;

int n, m;
char qusCom[N][N];
int sorceSum[N], maxSorce;
pair<int, int> qusSort[N];

bool sortPair(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int tmp;
        cin >> tmp;
        qusSort[i] = {tmp, i};
    }

    for (int i = 0; i < n; i ++) {
        bool plus = false;
        for (int j = 0; j < m; j ++) {
            cin >> qusCom[i][j];
            if (qusCom[i][j] == 'o') {
                sorceSum[i] += qusSort[j].first;
                plus = true;
            }
        }
        sorceSum[i] += i + 1;
        maxSorce = max(sorceSum[i], maxSorce);
    }
    // cout << maxSorce << endl;
    sort(qusSort, qusSort + m, sortPair);
    // for (int i = 0; i < m; i ++) {
    //     cout << qusSort[i].first << ' ' << qusSort[i].second << endl;
    // }
    // for (int i = 0; i < n; i ++) cout << sorceSum[i] << ' ';
    // puts("");

    for (int i = 0; i < n; i ++) {
        int cnt = 0;
        int tmp = 0;
        if (sorceSum[i] < maxSorce) {
            int target = maxSorce - sorceSum[i];
            // cout << target << " " << endl;
            for (int j = 0; j < m; j ++) {
                if (tmp < target) {
                    if (qusCom[i][qusSort[j].second] == 'x') {
                        tmp += qusSort[j].first;
                        cnt ++;
                    }
                } else {
                    break;
                }
            }
            if (tmp >= target) cout << cnt << endl;
        } else cout << 0 << endl;
    } 
    
    return 0;
}