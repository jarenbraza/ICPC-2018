#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T, n, bestCandidate, currVotes, mostVotes, totalVotes;
    bool hasWinner;
    cin >> T;

    while (T--) {
        cin >> n;

        bestCandidate = 0, mostVotes = 0, totalVotes = 0;
        hasWinner = false;
        for (int i = 1; i <= n; i++) {
            cin >> currVotes;
            totalVotes += currVotes;
            
            if (currVotes > mostVotes) {
                bestCandidate = i;
                mostVotes = currVotes;
                hasWinner = true;
            } else if (currVotes == mostVotes)
                hasWinner = false;
        }

        if (hasWinner) {
            if (mostVotes > totalVotes / 2)
                cout << "majority winner " << bestCandidate << endl;
            else
                cout << "minority winner " << bestCandidate << endl;
        }
        else
            cout << "no winner" << endl;
    }

    return 0;
}