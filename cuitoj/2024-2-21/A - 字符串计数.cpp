#include <iostream>
#include <string>
#include <unordered_map>

const int N = 1600;

int n;
int res;

using namespace std;

int main(void) {
    cin >> n;
    unordered_map<string, bool> strMap;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        if (strMap.count(s) == 0) {
            strMap.insert({s, true});
            res ++;
        }
    }

    cout << res << endl;
}