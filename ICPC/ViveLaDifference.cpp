#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a, b, c, d, temp, steps;

    while (cin >> a >> b >> c >> d && !(a == 0 && b == 0 && c == 0 && d == 0)) {
        steps = 0;
        
        while (a != b || b != c || c != d || d != a) {
            temp = a;
            a = abs(a - b);
            b = abs(b - c);
            c = abs(c - d);
            d = abs(d - temp);
            steps++;
        }

        cout << steps << endl;
    }

    return 0;
}