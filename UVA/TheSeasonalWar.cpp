#include <iostream>
#include <vector>
using namespace std;

#define DIRECTIONS 8

const short dx[DIRECTIONS] = {-1, -1, -1,  0,  0,  1,  1,  1};
const short dy[DIRECTIONS] = {-1,  0,  1, -1,  1, -1,  0,  1};

void concealEagle(vector<vector<char>>& cells, short i, short j, short n);

int main() {
    short i, j, n, numEagles, testcase = 1;

    while (cin >> n) {
        vector<vector<char>> cells(n, vector<char>(n));

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cin >> cells[i][j];

        numEagles = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cells[i][j] == '1') {
                    concealEagle(cells, i, j, n);
                    numEagles++;
                }
            }
        }

        cout << "Image number " << testcase++ << " contains " << numEagles << " war eagles." << endl;
    }

    return 0;
}

void concealEagle(vector<vector<char>>& cells, short i, short j, short n) {
    if (i < 0 || i >= n || j < 0 || j >= n || cells[i][j] == '0')
        return;

    cells[i][j] = '0';
    for (short k = 0; k < DIRECTIONS; k++)
        concealEagle(cells, i + dx[k], j + dy[k], n);
}