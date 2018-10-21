// 6795 - Palindrome Numbers

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string& s);
void toNextPalindrome(string& s);

int main() {
    string s;
    int T;
    cin >> T;

    while (T--) {
        cin >> s;

        if (!isPalindrome(s))
            toNextPalindrome(s);
        
        cout << s << endl;
    }

    return 0;
}

bool isPalindrome(string& s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}

void toNextPalindrome(string& s) {
    int mid = s.length() / 2;
    bool validNextPalindrome = true;
    int L = mid - 1;
    int R = (s.length() % 2 == 0 ? mid : mid + 1);

    while (L >= 0 && s[L] == s[R])
        L--, R++;

    if (L < 0 || s[L] < s[R])
        validNextPalindrome = false;

    while (L >= 0) {
        s[R] = s[L];
        L--, R++;
    }

    if (!validNextPalindrome) {
        int carry = 1;
        int curr = 0;
        L = mid - 1;

        if (s.length() % 2 == 0)
            R = mid;
        else {
            curr = s[mid] - '0' + carry;
            carry = curr / 10;
            s[mid] = (curr % 10) + '0';
            R = mid + 1;
        }

        while (L >= 0) {
            curr = s[L] - '0' + carry;
            carry = curr / 10;
            s[L] = (curr % 10) + '0';
            s[R] = s[L];
            L--, R++;
        }
    }
}
