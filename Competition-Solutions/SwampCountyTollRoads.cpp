#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    char c;
    string s;
    double d;
    unordered_map<char, double> probabilityMap;

    while ((getline(cin, s)) && (!s.empty())) {
        c = s[0];
        d = stod(s.substr(2));
        probabilityMap[c] = d;
    }

    cout << setprecision(3) << fixed;
    while ((getline(cin, s)) && (!s.empty())) {
        double probability = 1.000000000000000;
        for (char x : s)
            if (probabilityMap.find(x) != probabilityMap.end())
                probability *= probabilityMap[x];
        cout << probability << endl;
    }

    return 0;
}
