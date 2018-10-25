// 4937 - T-Shirt Size Distribution

#include <iostream>
#include <vector>
using namespace std;

#define NUM_SIZES 7

int main() {
    int N, P, i, remaining;
    vector<int> n(NUM_SIZES);

    while (cin >> n[0]) {
        vector<int> p(NUM_SIZES);

        N = n[0];
        for (i = 1; i < NUM_SIZES; i++) {
            cin >> n[i];
            N += n[i];
        }

        cin >> P;
        remaining = P;

        if (N != 0) {
            for (i = 0; i < NUM_SIZES; i++) {
                p[i] = P * n[i] / N;
                remaining -= p[i];
            }
        }

        for (i = 0; i < NUM_SIZES; i++) {
            if (remaining == 0)
                break;
            if (p[i] == 0)
                p[i]++, remaining--;
        }
        
        if (remaining > 0)
            p[4] += remaining;

        for (i = 0; i < NUM_SIZES - 1; i++)
            cout << p[i] << ' ';
        cout << p[6] << endl;
    }

    return 0;
}
