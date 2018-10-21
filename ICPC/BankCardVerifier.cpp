// 8322 - Bank Card Verifier

#include <iostream>
#include <string>
using namespace std;

#define CARD_NUM_LENGTH 16

int main() {
    string s;
    int oddSum, evenSum, i, j;

    while (getline(cin, s) && s != "0000 0000 0000 0000") {

        // Place first 16 non-space characters to left of string for ease
        for (i = 0, j = 0; j < s.length(); j++) {
            if (s[j] != ' ')
                s[i++] = s[j];
        }

        oddSum = 0, evenSum = 0;
        for (i = 0; i < CARD_NUM_LENGTH; i++) {
            if (i % 2 != 0 || s[i] == '9')
                evenSum += (s[i] - '0');
            else
                oddSum += (s[i] - '0') * 2 % 9;
        }

        if ((oddSum + evenSum) % 10 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
