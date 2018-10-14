#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

double roundToThreePlaces(double d) {
    return round(d * 1000.0) / 1000.0;
}

int main() {
    string time;
    double H, M, lowestDegree;

    while ((cin >> time) && (time != "0:00")) {
        if (time[2] == ':') {
            H = (double)stoi(time.substr(0, 2));
            M = (double)stoi(time.substr(3, 2));
        } else {
            H = (double)stoi(time.substr(0, 1));
            M = (double)stoi(time.substr(2, 2));
        }

        H = 30.0 * H + 0.5 * M;
        M *= 6;
        lowestDegree = min(abs(H - M), 360.0 - abs(H - M));

        cout << setprecision(3) << fixed;
        cout << roundToThreePlaces(lowestDegree) << endl;
    }

    return 0;
}
