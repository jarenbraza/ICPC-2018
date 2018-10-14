#include <iostream>
#include <string>
using namespace std;

int main() {
    int i;
    bool valid;
    string phrase;

    while (getline(cin, phrase) && phrase != "END") {
        int letterCount[26] = { 0 };
        valid = true;

        for (i = 0; i < phrase.length(); i++) {
            if (phrase[i] == ' ')
                continue;

            if (++letterCount[phrase[i] - 'A'] > 1) {
                valid = false;
                break;
            }
        }

        if (!valid)
            continue;
        
        cout << phrase << endl;
    }

    return 0;
}