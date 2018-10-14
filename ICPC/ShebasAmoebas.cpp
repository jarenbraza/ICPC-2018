#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy[8] = {-1,  0,  1, -1,  1, -1,  0,  1};

bool inBounds(int i, int j, int r, int c);
void DFS(vector<vector<char>>& grid, int i, int j);

int main() {
    int i, j, r, c, res;
    while (cin >> r >> c) {
        int res = 0;
        vector<vector<char>> grid(r, vector<char>(c));
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                cin >> grid[i][j];

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j] == '#') {
                    DFS(grid, i, j);
                    res++;
                }
            }
        }

        cout << res << endl;
    }
}

bool inBounds(int i, int j, int r, int c) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

void DFS(vector<vector<char>>& grid, int i, int j) {
    if (!inBounds(i, j, grid.size(), grid[0].size()) || grid[i][j] != '#')
        return;

    grid[i][j] = '.';

    int count = 0;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (inBounds(x, y, grid.size(), grid[0].size()) && grid[x][y] == '#') {
            DFS(grid, x, y);
            count++;
        }
        if (count == 2)
            break;
    }
}