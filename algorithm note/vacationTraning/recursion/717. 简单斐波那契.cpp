#include <iostream>

using namespace std;

int n;

int fbnc(int n) {
    if (n > 1)
        cout << fbnc(n - 1) + fbnc(n - 2)<< endl;
    else 
        {cout << 0 << ' ' << 1;}

    return n;
}

int main(void) {
    cin >> n;
    fbnc(n);
    return 0;
}