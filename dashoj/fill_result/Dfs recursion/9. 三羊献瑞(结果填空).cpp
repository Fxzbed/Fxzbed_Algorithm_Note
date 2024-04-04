/* LQ0023 三羊献瑞 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (; ;) {
        if (a[0] != 0 && a[4] != 0) {
            int sum1 = a[4] * 1000 + a[3] * 100 + a[5] * 10 + a[6];
            int sum2 = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
            int sum = a[0] * 10000 + a[1] * 1000 + a[5] * 100 + a[3] * 10 + a[7];
            if (sum1 + sum2 == sum) {
                printf("%d\n", sum2);
                break;
            }
        }
        next_permutation(a, a +10);
    }
    return 0;
}
