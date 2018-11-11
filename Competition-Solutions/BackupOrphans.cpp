#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

string root(string s) {
    int count = 0;
    int len = s.length();
    int end = len - 1;

    for (int i = 0; i < len; i++) {
        if (s[len - i - 1] == '_')
            count++;
        if (count == 2) {
            end = len - i - 1;
            break;
        }
    }
    return s.substr(0, end);
}

int main() {
    set<string> blockSet1, blockSet2, rootSet2;
    string s;

    while (getline(cin, s)) {
        if (s.empty())
            break;
        blockSet1.insert(s);
    }

    while (getline(cin, s)) {
        if (s.empty())
            break;
        blockSet2.insert(s);
        rootSet2.insert(root(s));
    }

    vector<string> res1;
    vector<string> res2;

    for (string s1 : blockSet1)
        if (rootSet2.find(s1) == rootSet2.end())
            res1.push_back(s1);

    for (string s2 : blockSet2)
        if (blockSet1.find(root(s2)) == blockSet1.end())
            res2.push_back(s2);

    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());

    if (res1.empty() && res2.empty())
        cout << "No mismatches." << endl;
    else {
        for (string s : res2)
            cout << "F " << s << endl;

        for (string s : res1)
            cout << "I " << s << endl;
    }

    return 0;
}
