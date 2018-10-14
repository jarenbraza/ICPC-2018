#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

#define GRAVITY 9.8

double roundHeight(double height) {
    return (double)round(height * 100.0) / 100.0;
}

int main() {
    double Ht, N, M, Tct, Tr;

    cout << setprecision(2) << fixed;
    while (cin >> N >> M >> Tct >> Tr)
        cout << roundHeight(GRAVITY / 2 * pow(((N - 1) / 2 * Tct) + (N / 2 * Tr), 2)) << endl;

    return 0;
}
