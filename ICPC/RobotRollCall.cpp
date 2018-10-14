#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t, n, testCase = 1;
    string s, substr;

    cin >> t;
    while (t--) {
        vector<string> roll;

        cin >> n;
        while (n--) {
            cin >> s;
            roll.push_back(s);
        }

        set<string> names(roll.begin(), roll.end());

        cin >> n;
        while (n--) {
            getchar();
            getline(cin, s);
            istringstream stream(s);
            do {
                stream >> substr;
                names.erase(substr);
            } while (stream);
        }

        cout << "Test set " << testCase++ << ":" << endl;

        for (int i = 0; i < roll.size(); i++)
            cout << roll[i] << " is " << (names.find(roll[i]) == names.end() ? "present" : "absent") << endl;

        cout << endl;
    }

    return 0;
}