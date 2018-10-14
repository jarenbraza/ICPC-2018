#include <iostream>
#include <vector>
using namespace std;

#define DIRECTIONS 8

const short dx[DIRECTIONS] = {-1, -1, -1,  0,  0,  1,  1,  1};
const short dy[DIRECTIONS] = {-1,  0,  1, -1,  1, -1,  0,  1};

bool validGridLocation(vector<vector<char>>& grid, int i, int j) {
    return (i >= 0) && (i < grid.size()) && (j >= 0) && (j < grid[0].size()) && (grid[i][j] == '@');
}

void DFS(vector<vector<char>>& grid, int i, int j) {
    if (!validGridLocation(grid, i, j))
        return;

    grid[i][j] = '*';

    int x, y;
    for (int k = 0; k < DIRECTIONS; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (validGridLocation(grid, x, y))
            DFS(grid, x, y);
    }
}

int main() {
    int i, j, m, n, distinctPockets;

    while ((cin >> m >> n) && (m != 0) && (n != 0)) {
        vector<vector<char>> grid(m, vector<char>(n));

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> grid[i][j];

        distinctPockets = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    DFS(grid, i, j);
                    distinctPockets++;
                }
            }
        }

        cout << distinctPockets << endl;
    }

    return 0;
}
