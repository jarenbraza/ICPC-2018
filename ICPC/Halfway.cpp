// DOESN'T WORK, SHOULD MAYBE GET IT TO WORK LATER :^)

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int res = 1;
        int curr = n - 1;
        long long remaining = n * (n - 1) / 2;
        while (curr > remaining) {
            remaining -= curr;
            curr--;
        }
        cout << res - curr << endl;
    }
    return 0;
}
