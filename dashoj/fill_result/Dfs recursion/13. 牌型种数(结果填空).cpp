#include <iostream> 

using namespace std;

int res;

void func(int u, int idx = 1) {
    if (u == 13) res ++;

    if (idx > 13 || u >= 13) return;

    for (int i = 0; i <= 4; i ++) {
        func(u + i, idx + 1);
    }
}

int main(void) {
    func(0);
    cout << res << endl;
    return 0;
}
