// 7633 - A Giveaway

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long n, squareRoot, cubeRoot;

    while ((cin >> n) && (n != 0)) {
        squareRoot = round(sqrt(n));
        cubeRoot = round(cbrt(n));

        if ((squareRoot * squareRoot == n) && (cubeRoot * cubeRoot * cubeRoot == n))
            cout << "Special" << endl;
        else
            cout << "Ordinary" << endl;
    }

    return 0;
}
