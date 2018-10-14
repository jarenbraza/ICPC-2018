#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, i, discount;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> costs(n);

        for (i = 0; i < n; i++)
            cin >> costs[i];

        sort(costs.begin(), costs.end());

        discount = 0;
        for (i = n - 3; i >= 0; i -= 3)
            discount += costs[i];

        cout << discount << endl;
    }

    return 0;
}