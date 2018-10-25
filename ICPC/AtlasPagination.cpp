// 4936 - Atlas Pagination

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C, r, c, pageNum;
    char x;

    while (cin >> R >> C) {
        vector<vector<int>> grid(R + 2, vector<int>(C + 2, 0));
        for (r = 1; r <= R; r++) {
            for (c = 1; c <= C; c++) {
                cin >> x;
                if (x == 'X')
                    grid[r][c] = 0;
                else
                    grid[r][c] = -1;
            }
        }

        pageNum = 1;
        for (r = 1; r <= R; r++)
            for (c = 1; c <= C; c++)
                if (grid[r][c] == -1)
                    grid[r][c] = pageNum++;

        for (r = 1; r <= R; r++)
            for (c = 1; c <= C; c++)
                if (grid[r][c] != 0)
                    cout << grid[r][c] << ' ' << grid[r - 1][c] << ' ' << grid[r][c + 1] << ' ' << grid[r + 1][c] << ' ' << grid[r][c - 1] << endl;

        cout << endl;
    }

    return 0;
}
