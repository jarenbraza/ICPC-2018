#include <iostream>
#include <string>
using namespace std;

#define MAX 2147483647

int main() {
    string s;
    int c, i, t, T, dist;
    cin >> T;

    for (t = 1; t <= T; t++) {
        short charMap[26] = { 0 };
        cin >> s;

        dist = MAX;
        for (i = 0; i < s.length(); i++) {
            c = s[i] - 'a';

            if (charMap[c] != 0)
                dist = min(dist, i + 1 - charMap[c]);

            charMap[c] = i + 1;
        }

        cout << "Case #" << t << ": " << (dist == MAX ? -1 : dist) << endl;
    }

    return 0;
}