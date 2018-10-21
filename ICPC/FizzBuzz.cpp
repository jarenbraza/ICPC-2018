#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, X, Y, N, n;
    string s;
    cin >> T;
    
    while (T--) {
        cin >> X >> Y >> N;

        for (n = 1; n <= N; n++) {
            s = "";
            if (n % X == 0)
                s += "Fizz";
            if (n % Y == 0)
                s += "Buzz";
            if (s.empty())
                cout << n << endl;
            else
                cout << s << endl;
        }
    }

    return 0;
}
