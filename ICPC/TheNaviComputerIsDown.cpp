#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;

double getDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
    return (double)((int)(pow(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2), 0.5) * 100 + 0.5)) / 100.0;
}

int main() {
    int n;
    double x1, y1, z1, x2, y2, z2;
    string s1, s2;
    cin >> n;

    while (n--) {
        getchar();
        getline(cin, s1);
        cin >> x1 >> y1 >> z1;

        getchar();
        getline(cin, s2);
        cin >> x2 >> y2 >> z2;

        printf("%s to %s: %.2f\n", s1.c_str(), s2.c_str(), getDistance(x1, x2, y1, y2, z1, z2));
    }
    
    return 0;
}