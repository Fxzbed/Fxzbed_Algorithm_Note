#include <iostream> 

using namespace std;

int a[9] = {2, 4, 5, 6, 7, 9, 10, 11, 12};

int main(void) {
    do {
        int x_1 = 1 + a[1] + a[4] + a[8];
        int x_2 = 1 + a[0] + a[3] + a[5];
        if (x_1 != x_2) continue;
        int x_3 = 8 + a[0] + a[1] + a[2];
        if (x_2 != x_3) continue;
        int x_4 = 8 + a[3] + a[6] + 3;
        if (x_3 != x_4) continue;
        int x_5 = a[2] + a[4] + a[7] + 3;
        if (x_4 != x_5) continue;
        int x_6 = a[5] + a[6] + a[7] + a[8];
        if (x_5 != x_6) continue;

        cout << a[3];
        break;
    } while (next_permutation(a, a + 9));


    return 0;
}