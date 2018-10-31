// 371 - Ackermann Functions

#include <iostream>
using namespace std;

int main() {
    long long lo, hi, V, maxLen, currLen, N;

    while ((cin >> lo >> hi) && !(lo == 0 && hi == 0)) {
        if (lo > hi)
            swap(lo, hi);

        V = 0;
        maxLen = 0;
        for (long long i = lo; i <= hi; i++) {
            currLen = 0;
            N = i;
            if (N == 1) {
                N = 3 * N + 1;
                currLen++;
            }
            while (N != 1) {
                N = (N % 2 == 0) ? (N / 2) : (3 * N + 1);
                currLen++;
            }
            if (currLen > maxLen) {
                maxLen = currLen;
                V = i;
            }
        }
        cout << "Between " << lo << " and " << hi << ", " << V << " generates the longest sequence of " << maxLen << " values." << endl;
    }

    return 0;
}
