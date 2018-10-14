#include <iostream>
#include <vector>
using namespace std;

void drownIsland(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 'W')
        return;
    
    grid[i][j] = 'W';
    drownIsland(grid, i - 1, j);
    drownIsland(grid, i + 1, j);
    drownIsland(grid, i, j - 1);
    drownIsland(grid, i, j + 1);
}

int main() {
    int i, j, r, c, numIslands;
    while (cin >> r >> c) {
        numIslands = 0;
        vector<vector<char>> grid(r, vector<char>(c));
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                cin >> grid[i][j];

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j] == 'L') {
                    drownIsland(grid, i, j);
                    numIslands++;
                }
            }
        }

        cout << numIslands << endl;
    }

    return 0;
}