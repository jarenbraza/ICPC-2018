// 8091 - Happy Number

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll x, n;

    while (cin >> n) {
        while ((n != 1) && (n != 4)) {
            x = 0;
            while (n != 0) {
                x += (n % 10) * (n % 10);
                n /= 10;
            }
            n = x;
        }
        if (n == 1)
            cout << "HAPPY" << endl;
        else
            cout << "UNHAPPY" << endl;
    }

    return 0;
}
