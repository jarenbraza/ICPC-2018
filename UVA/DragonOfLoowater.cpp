#include <iostream>
#include <queue>
using namespace std;

int main() {
    int i, j, n, m, x, cost; // #cleancode

    while ((cin >> n >> m) && (n != 0) && (m != 0)) {

        priority_queue<int, vector<int>, greater<int>> heads;
        priority_queue<int, vector<int>, greater<int>> heights;

        // Read in head diameters into min-heap
        for (i = 0; i < n; i++) {
            cin >> x;
            heads.push(x);
        }

        // Read in knight heights into min-heap
        for (i = 0; i < m; i++) {
            cin >> x;
            heights.push(x);
        }

        cost = 0;

        //  Hire knight of minimum height for the currently smallest head diameter
        while (!heads.empty() && !heights.empty()) {
            if (heights.top() >= heads.top()) {
                cost += heights.top();
                heads.pop();
            }
            heights.pop();
        }

        // If all heads had a corresponding knight to deal with it, then print cost
        // Otherwise, there was a head that no knight could deal with, so print doom message
        if (heads.empty())
            cout << cost << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }

    return 0;
}