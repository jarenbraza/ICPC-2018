// 7612 - Thickest Burger

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T, A, B;
    cin >> T;

    while (T--) {
        cin >> A >> B;
        cout << max(A + A + B, A + B + B) << endl;
    }

    return 0;
}
