#include <iostream>
using namespace std;

int getCycleLength(int n) {
    int len = 0;
    while (n != 1) {
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n /= 2;
        len++;
    }
    return len + 1;
}

int main() {
    int maxLen, i, j, curr;
    
    while (cin >> i >> j) {
        maxLen = 0;
        for (curr = min(i, j); curr <= max(i, j); curr++)
            maxLen = max(maxLen, getCycleLength(curr));
        cout << i << ' ' << j << ' ' << maxLen << endl;
    }

    return 0;
}