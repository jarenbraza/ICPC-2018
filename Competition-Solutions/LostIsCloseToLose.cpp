#include <algorithm>
#include <cctype>
#include <iostream>
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

string core(string s) {
    int idx = 0;

    while (idx < s.length()) {
        if (!isalpha(s[idx]))
            s.erase(s.begin() + idx);
        else {
            s[idx] = tolower(s[idx]);
            idx++;
        }
    }

    return s;
}

bool canDel(string s1, string s2) {

    int l1 = s1.length(), l2 = s2.length();
    if (abs(l1 - l2) != 1)
        return false;

    if (l1 < l2) {
        string s = s1;
        s1 = s2;
        s2 = s;
    }

    l1 = s1.length(), l2 = s2.length();

    for (int i = 0; i < l1; i++)
        if ((s1.substr(0, i) + s1.substr(i + 1, l1 - i - 1)) == s2)
            return true;

    return false;
}

bool canReplace(string& s1, string& s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    if (abs(l1 - l2) != 0)
        return false;

    bool hasDiff = false;

    for (int i = 0; i < l1; i++) {
        if (s1[i] != s2[i]) {
            if (hasDiff)
                return false;
            hasDiff = true;
        }
    }

    return hasDiff;
}

bool canTranspose(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    if (abs(l1 - l2) != 0)
        return false;

    for (int i = 0; i < l1 - 1; i++) {
        if (s1[i] != s2[i]) {
            char c = s1[i];
            s1[i] = s1[i + 1];
            s1[i + 1] = c;
            return (s1 == s2);
        }
    }

    return false;
}

int main() {
    string s;
    set<string> words;
    map<string, set<string>> m;

    while ((cin >> s) && (s != "***")) {
        if (s.empty() || core(s).empty())
            continue;
        words.insert(core(s));
    }

    vector<string> arr(words.begin(), words.end());

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (i == j)
                continue;

            string s1 = arr[i];
            string s2 = arr[j];

            // Note: If can delete s1 to s2, then can insert s2 to s1
            if (canDel(s1, s2) || canReplace(s1, s2) || canTranspose(s1, s2)) {
                m[s1].insert(s2);
                m[s2].insert(s1);
            }
        }
    }

    if (m.empty())
        cout << "***" << endl;
    else {
        for (pair<string, set<string>> p : m) {
            cout << p.first << ": ";
            for (set<string>::iterator it = p.second.begin(); it != p.second.end(); it++) {
                if (it != p.second.begin())
                    cout << " ";
                cout << *it;
            }
            cout << endl;
        }
    }
    return 0;
}
