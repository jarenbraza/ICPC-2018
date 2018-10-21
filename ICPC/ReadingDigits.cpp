#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, finalEncoding;
    int k, pos, i, n;

    while (cin >> k >> pos) {
        cin >> s;

        while (k--) {
            finalEncoding = "";
            for (i = 0; i < s.length(); i += 2) {
                n = s[i] - '0';
                while (n--)
                    finalEncoding += s[i + 1];
            }
            s = finalEncoding;
        }

        cout << finalEncoding[pos] << endl;
    }

    return 0;
}
