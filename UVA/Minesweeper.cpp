#include <iostream>
#include <vector>
using namespace std;

#define DIRECTIONS 8

const short dx[DIRECTIONS] = {-1, -1, -1,  0,  0,  1,  1,  1};
const short dy[DIRECTIONS] = {-1,  0,  1, -1,  1, -1,  0,  1};

void incrementSurroundings(vector<vector<char>>& grid, int r, int c) {
    int x, y;

    for (int k = 0; k < DIRECTIONS; k++) {
        x = r + dx[k];
        y = c + dy[k];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != '*')
            grid[x][y]++;
    }
}

int main() {
    char fieldEntry;
    int r, c, n, m, t = 1; // #cleancode

    while ((cin >> n >> m) && (n != 0) && (m != 0)) {
        // Preprocess grid of zeros, where only * inputs are set
        vector<vector<char>> grid(n, vector<char>(m, '0'));
        for (r = 0; r < n; r++) {
            for (c = 0; c < m; c++) {
                cin >> fieldEntry;
                if (fieldEntry == '*')
                    grid[r][c] = '*';
            }
        }

        // Increment the grid spots adjacent to *'s that are not *'s themselves
        for (r = 0; r < n; r++)
            for (c = 0; c < m; c++)
                if (grid[r][c] == '*')
                    incrementSurroundings(grid, r, c);

        // Print results
        if (t != 1)
            cout << endl;
        cout << "Field #" << t++ << ":" << endl;
        for (r = 0; r < n; r++) {
            for (c = 0; c < m; c++) {
                cout << grid[r][c];
            }
            cout << endl;
        }
    }

    return 0;
}

