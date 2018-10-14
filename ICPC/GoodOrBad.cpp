#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string name;
    int rating, n;
    cin >> n;

    getchar();
    while (n--) {
        getline(cin, name);
        rating = 0;
        for (char c : name) {
            if (tolower(c) == 'b')
                rating--;
            else if (tolower(c) == 'g')
                rating++;
        }

        if (rating < 0)
            cout << name << " is A BADDY" << endl;
        else if (rating == 0)
            cout << name << " is NEUTRAL" << endl;
        else
            cout << name << " is GOOD" << endl;
    }

    return 0;
}