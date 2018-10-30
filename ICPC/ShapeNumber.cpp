// 5734 - Shape Number

#include <iostream>
#include <string>
using namespace std;

int search(string& s, int len) {
    int i = 0, j = 1, k = 0;
    int pos1, pos2, diff;

    while ((i < len) && (j < len) && (k < len)) {
        pos1 = (i + k) % len;
        pos2 = (j + k) % len;
        diff = s[pos1] - s[pos2];

        if (diff == 0)
            k++;
        else {
            if (diff > 0)
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }

    return i;
}

int main() {
    string chainCode, s;
    int i, len, bestIndex;

    while (cin >> chainCode) {
        len = chainCode.length();
        s.resize(chainCode.length());

        // Generate the first difference of the chain code
        for (i = 0; i < len; i++)
            s[i] = (chainCode[(i + 1) % len] - chainCode[i] + 8) % 8 + '0';

        // Search for best starting index
        bestIndex = search(s, len);

        // Print lexicographically smallest cyclic rotation of the string using the best starting index 
        cout << s.substr(bestIndex, len - bestIndex) << s.substr(0, bestIndex) << endl;
    }

    return 0;
}
