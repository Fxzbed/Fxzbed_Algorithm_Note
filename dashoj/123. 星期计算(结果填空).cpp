#include <iostream>
#include <cmath>

using namespace std;
 
const int N = ((int)pow(20, 22) % 7);

int main(void) {
    int x = 6;
    for (int i = 1; i <= N; i ++) {
        if (x == 7) x = 1;
        else x ++;
    }
    cout << x << endl;
    return 0;
}