#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

const string endStr = "12345678x";

string moveX(string str, int index, int kind) {
    int add = 0;
    if (kind == 0) add = 1;
    else if (kind == 1) add = -1;
    else if (kind == 2) add = -3;
    else if (kind == 3) add = 3;
    swap(str[index], str[index + add]);
    // cout << res << endl;
    return str;
}

int bfs(string& start) {
    queue<string> q;
    unordered_map<string, int> dist;
    q.push(start);
    dist[start] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int distance = dist[t];
        if (t == endStr) return distance;
        auto index = t.find('x');
        // cout << "index:"<< index << endl;

        bool jd[4] = {true, true, true, true};
        //列出状态转移
        if (index == 2 || index == 5 || index == 8) {
            jd[0] = false;  //right
        }
        if (index == 0 || index == 3 || index == 6) {
            jd[1] = false;  //left
        }   
        if (index == 0 || index == 1 || index == 2) {
            jd[2] = false;  //up
        }
        if (index == 6 || index == 7 || index == 8) {
            jd[3] = false;  //down
        }

        for (int i = 0; i < 4; i ++) {
            if (jd[i]) {
                string tmp = moveX(t, index, i);
                if (!dist.count(tmp)) {
                    q.push(tmp);
                    dist[tmp] = distance + 1;
                }
            }
        }
    }
    return -1;
}

int main(void) {
    string start;
    for (int i = 0; i < 9; i ++) {
        char tmp;
        cin >> tmp;
        start += tmp;
    }
    if (start != endStr) 
        cout << bfs(start) << endl;
        // bfs(start);
    else 
        printf("0");
    return 0;
}