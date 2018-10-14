#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define MAX_SPENDING 5e6

int main() {
    long long T, L, i, p, res, total;
    bool tooExpensive;
    cin >> T;

    while (T--) {
        vector<long long> arr;
        tooExpensive = false;
        total = 0;
        i = 1;

        while ((cin >> L) && (L != 0))
            arr.push_back(L);
        sort(arr.begin(), arr.end(), greater<long long>());

        for (long long e : arr) {
            res = 1;
            for (p = 0; p < i; p++)
                res *= e;
            total += res;
            i++;
            
            if (total * 2 > MAX_SPENDING) {
                tooExpensive = true;
                break;
            }
        }

        if (tooExpensive)
            cout << "Too expensive" << endl;
        else
            cout << total * 2 << endl;
    }

    return 0;
}
