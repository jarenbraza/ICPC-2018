// 926 - Walking Around Wisely

#include <iostream>
#include <vector>
using namespace std;

void generateBlocks(vector<vector<bool>>& rowBlocked, vector<vector<bool>>& colBlocked, long long W);

int main() {
    long long C, N, W, r0, r1, c0, c1, r, c; // #cleancode
    cin >> C;

    while (C--) {
        // Read in size, start coordinates, and end coordinates
        cin >> N >> r0 >> c0 >> r1 >> c1;

        // Generate memoization grid with one extra space to account for border check
        vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));

        // Generate row and column block checks with one extra space
        // Extra space this time is because block occurs between streets rather than on them
        vector<vector<bool>> rowBlocked(N + 1, vector<bool>(N + 1, false));
        vector<vector<bool>> colBlocked(N + 1, vector<bool>(N + 1, false));

        // Read in which crossings are blocked
        cin >> W;
        generateBlocks(rowBlocked, colBlocked, W);

        // Repeated work on repeated adds going up and right
        // Thus, just add on non-blocked ways coming from the left and coming from below for each spot
        // Basis step is at 1 and not zero because if start == end, then there is a single path (itself)
        dp[r0][c0] = 1;
        for (r = r0; r <= r1; r++) {
            for (c = c0; c <= c1; c++) {
                // If coming from south is not blocked, add ways to come from south
                if (!rowBlocked[r - 1][c])
                    dp[r][c] += dp[r - 1][c];

                // If coming from west is not blocked, add ways to come from west
                if (!colBlocked[r][c - 1])
                    dp[r][c] += dp[r][c - 1];
            }
        }

        // Output result at end coordinates
        cout << dp[r1][c1] << endl;
    }

    return 0;
}

void generateBlocks(vector<vector<bool>>& rowBlocked, vector<vector<bool>>& colBlocked, long long W) {
    long long x, y;
    char direction;

    while (W--) {
        cin >> x >> y >> direction;
        if      (direction == 'N') colBlocked[x][y]     = true;
        else if (direction == 'E') rowBlocked[x][y]     = true;
        else if (direction == 'S') colBlocked[x][y - 1] = true;
        else if (direction == 'W') rowBlocked[x - 1][y] = true;
    }
}
