#include <algorithm>
#include <iostream>
using namespace std;

const int t[6] = {30, 40, 35, 30, 40, 20};

int main() {
    int c, d;

    while ((cin >> c >> d) && (c != 0) && (d != 0))
        cout << min(min(c*t[0]+d*t[1], c*t[2]+d*t[3]), c*t[4]+d*t[5]) << endl;

    return 0;
}