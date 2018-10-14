#include <iostream>
using namespace std;

#define MAX_PILLS 30

int main() {
    int i, j, n;
    long long arr[MAX_PILLS + 1][MAX_PILLS + 1] = {0};

    // Only one possibility if only half pills remain
    for (i = 0; i <= MAX_PILLS; i++) {
            arr[i][0] = 1;
            arr[i][1] = i + 1;
    }
    arr[0][0] = 0;

    // ...WWW = ...WWH = ...WW + ...WHH
    for (j = 2; j <= MAX_PILLS; j++) {
        for (i = 0; i <= MAX_PILLS - j; i++) {
            if (i == 0)
                arr[i][j] = arr[i + 1][j - 1];
            else
                arr[i][j] = arr[i + 1][j - 1] + arr[i - 1][j];
        }
    }

    while (cin >> n && n != 0)
        cout << arr[0][n] << endl;

    return 0;
}