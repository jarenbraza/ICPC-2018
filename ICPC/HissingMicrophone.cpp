// 8221 - Hissing Microphone

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;

    while (cin >> s) {
        int sCount = 0;
        bool resultFound = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 's')
                sCount++;
            else if (sCount == 2) {
                resultFound = true;
                cout << "hiss" << endl;
                break;
            }
            else
                sCount = 0;
        }
        if (!resultFound) {
            if (sCount == 2)
                cout << "hiss" << endl;
            else
                cout << "no hiss" << endl;
        }
    }

    return 0;
}
