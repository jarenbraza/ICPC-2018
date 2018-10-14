#include <iostream>
using namespace std;

int main() {
    int P, K, N;

    cin >> P;
    while (P--) {
        cin >> K >> N;
        cout << K << " " << N * (N + 1) / 2 << " " << N * N << " " << N * (N + 1) << endl;
    }

    return 0;
}