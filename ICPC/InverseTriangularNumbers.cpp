// 5958 - Inverse Triangular Numbers

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    unordered_map<ll, ll> triangularNumbers;

    for (ll i = 1, j = 1; i < 10e9; i += j + 1, j++)
        triangularNumbers[i] = j;

    while (cin >> N) {
        if (triangularNumbers.find(N) == triangularNumbers.end())
            cout << "bad" << endl;
        else
            cout << triangularNumbers[N] << endl;
    }

    return 0;
}
