#include <iostream>
using namespace std;

int main() {
    int T = 1;
    int total, res, N, sideLen, originalLen;
    cin >> N;
    while (N--) {
        cin >> sideLen;
        originalLen = sideLen;
        total = 0;
        res = 0;
        for (int i = 1; i <= sideLen; i++) {
            res += i;
            total += res;
        }
        cout << T++ << ": " << originalLen << " " << total << endl;
    }

    return 0;
}