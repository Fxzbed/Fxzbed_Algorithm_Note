#include <bits/stdc++.h>

using namespace std;

const double N = 23333333;
const string ans = "11625907.5798";

int main(void) {
    int t = 0;
    for (t = 0; t <= N; t += 1) {
        double p_0 = t / N;
        double p_1 = (N - t) / N; 
        double tmp = ((t * -p_0 * log2(p_0)) + ((N - t) * -p_1 * log2(p_1)));
        char fin[ans.size()];
        sprintf(fin, "%.4f", tmp);
        if (ans == fin) {
            cout << t;
            break;
        }
    }
    return 0;
}