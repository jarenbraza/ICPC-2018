#include <iostream>
using namespace std;

int main() {
    long long sum, work;
    int i, n;

    while (cin >> n && n != 0) {
        sum = 0;
        work = 0;

        while (n--) {
            cin >> i;
            sum += i;
            if (sum < 0)
                work -= sum;
            else
                work += sum;
        }

        cout << work << endl;
    }

    return 0;
}