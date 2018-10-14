#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string cityName;
    int T, n, i;
    cin >> T;

    while (T--) {
        set<string> uniqueCities;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> cityName;
            uniqueCities.insert(cityName);
        }
        cout << uniqueCities.size() << endl;
    }

    return 0;
}