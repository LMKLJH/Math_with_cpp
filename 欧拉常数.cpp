#include <iostream>
#include <cmath>

using namespace std;

double compute_e(int n) {
    double e = 1.0;
    double factorial = 1.0;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        e += 1.0 / factorial;
    }
    return e;
}

int main() {
    int n = 1000000;
    double e = compute_e(n);
    cout << "e = " << e << endl;
    return 0;
}

