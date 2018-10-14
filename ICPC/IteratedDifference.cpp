#include <iostream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;

#define MAX_ITERATIONS 1000

bool allSameValue(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] != arr[i - 1])
            return false;
    return true;
}

int main() {
    int i, n, iterations, leftmost, testcase = 1;
    bool attainable;

    while (cin >> n && n != 0) {
        vector<int> a(n);
        attainable = true;
        for (i = 0; i < n; i++)
            cin >> a[i];

        iterations = 0;
        while (!allSameValue(a)) {
            if (iterations == MAX_ITERATIONS) {
                attainable = false;
                break;
            }
            leftmost = a[0];
            for (i = 0; i < n - 1; i++)
                a[i] = abs(a[i] - a[i + 1]);
            a[n - 1] = abs(a[n - 1] - leftmost);
            iterations++;
        }

        if (attainable)
            cout << "Case " << testcase++ << ": " << iterations << " iterations" << endl;
        else
            cout << "Case " << testcase++ << ": not attained" << endl;
    }

    return 0;
}