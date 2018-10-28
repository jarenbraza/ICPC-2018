// 8228 - Heart Rate

#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

#define MINUTE 60

double roundDbl(double x) {
    return round(x * 10000.0) / 10000.0;
}

int main() {
    int b, N;
    double p, offset, bpm;
    cin >> N;
    cout << setprecision(4) << fixed;

    while (N--) {
        cin >> b >> p;
        offset = MINUTE / p;
        bpm = MINUTE * b / p;

        cout << roundDbl(bpm - offset) << ' ' << roundDbl(bpm) << ' ' << roundDbl(bpm + offset) << endl;
    }

    return 0;
}
