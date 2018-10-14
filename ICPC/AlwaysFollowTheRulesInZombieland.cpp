#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> rules;
    string s;
    int i, n, r;
    cin >> n;

    getchar();
    for (i = 1; i <= n; i++) {
        getline(cin, s);
        rules[i] = s;
    }
    
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> r;
        if (rules.find(r) == rules.end())
            cout << "Rule " << r << ": No such rule" << endl;
        else
            cout << "Rule " << r << ": " << rules[r] << endl;
    }

    return 0;
}
