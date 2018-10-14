#include <iostream>
using namespace std;

int main() {
    long long P, t, n, largest;
    cin >> P;

    while (P--) {
        cin >> t >> n;

        largest = n;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
            largest = max(largest, n);
        }

        cout << t << " " << largest << endl;
    }

    return 0;
}