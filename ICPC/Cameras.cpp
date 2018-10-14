#include <iostream>
#include <string>
using namespace std;

bool isNum(char c) {
    return (c >= '1' && c <= '9');
}

bool isTrueCarNumber(const string& s) {
    if (s.length() != 8)
        return false;
    
    if (s[0] != s[1] || !isNum(s[0]) || !isNum(s[1]))
        return false;

    if (!isNum(s[2]) || !isNum(s[3]))
        return false;

    if (s[4] < 'A' || s[4] > 'Z')
        return false;

    if (!isNum(s[5]) || !isNum(s[6]) || !isNum(s[7]))
        return false;

    return true;
}

int main() {
    string s;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        if (isTrueCarNumber(s))
            cout << s << endl;
    }
    return 0;
}