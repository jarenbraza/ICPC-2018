// 5779 - Vampire Numbers

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> generateVampireNumbers();
bool isVampireNumber(int v, int a, int b);
int getNextVampireNumber(vector<int>& vampNums, int X);

int main() {
    vector<int> vampNums = generateVampireNumbers();
    sort(vampNums.begin(), vampNums.end());
    int X;

    while ((cin >> X) && (X != 0))
        cout << getNextVampireNumber(vampNums, X) << endl;

    return 0;
}

vector<int> generateVampireNumbers() {
    vector<int> vampNums;
    int a, b, candidate;

    // Brute force all of the possible vampire numbers
    // This way avoids repetition of work in main program
    // (Example: Two or more of the same input is given)
    for (a = 2; a <= 1e3; a++) {
        // Note that 1000255 is next smallest vampire number after 10e6, the largest possible input
        for (b = a; (b <= 1e6) && (a * b <= 1000255); b++) {
            candidate = a * b;
            if (isVampireNumber(candidate, a, b))
                vampNums.push_back(candidate);
        }
    }

    return vampNums;
}

bool isVampireNumber(int v, int a, int b) {
    string s1 = to_string(v);
    string s2 = to_string(a) + to_string(b);

    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.length(); i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

// Modified binary search to get next vampire number greater than or equal to X
int getNextVampireNumber(vector<int>& vampNums, int X) {
    int lo = 0;
    int hi = vampNums.size();
    int mid;

    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (vampNums[mid] < X)
            lo = mid + 1;
        else
            hi = mid;
    }

    return vampNums[lo];
}

/* Time limit exceeded, even with lower time complexity than that of the other implementation!
bool isVampireNumber(int v, int a, int b) {
    unordered_map<int, int> digitCounts;

    // Count and remove rightmost digit for a
    while (a != 0) {
        digitCounts[a % 10]++;
        a /= 10;
    }

    // Count and remove rightmost digit for b
    while (b != 0) {
        digitCounts[b % 10]++;
        b /= 10;
    }

    // Count and remove rightmost digit for candidate, v
    // Subtract as digits in v are compared to those of concatenation of a and b
    while (v != 0) {
        digitCounts[v % 10]--;
        v /= 10;
    }

    // Return false if count of a digit does not match between v and concatenation of a and b
    for (const pair<int, int>& digitCount : digitCounts)
        if (digitCount.second != 0)
            return false;
    return true;
}
*/

// As a minor note, runtime can be cut dramatically (by a second) by utilizing less functions
