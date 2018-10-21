// 7613 - Relative Atomic Mass

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int T, mass;
    cin >> T;

    while (T--) {
        cin >> s;
        mass = 0;
        for (char c : s) {
            if (c == 'H')
                mass += 1;
            else if (c == 'C')
                mass += 12;
            else
                mass += 16;
        }
        cout << mass << endl;
    }

    return 0;
}
