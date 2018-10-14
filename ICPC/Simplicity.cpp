#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

#define NUM_LOWERCASES 26

int main() {
    string s;
    int distinct, minRemovals, i;

    while (cin >> s) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        set<char> uniqueChars;
        int charCount[NUM_LOWERCASES] = { 0 };

        for (char c : s) {
            uniqueChars.insert(c);
            charCount[c - 'a']++;
        }

        distinct = uniqueChars.size();
        for (char c : uniqueChars)
            minHeap.push(charCount[c - 'a']);
        
        minRemovals = 0;
        while (distinct > 2) {
            minRemovals += minHeap.top();
            distinct--;
            minHeap.pop();
        }

        cout << minRemovals << endl;
    }

    return 0;
}