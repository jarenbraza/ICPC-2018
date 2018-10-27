#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool isLatinSquare(vector<vector<int>>& arr);
bool isReducedForm(vector<vector<int>>& arr);

int main() {
    int i, j, squareLength;
    char c;

    while (cin >> squareLength) {
        // 2D array that is checked to be Latin and in reduced form
        vector<vector<int>> square(squareLength, vector<int>(squareLength));

        // Read into array, where '0' = 0, '1' = 1, ..., '9' = 9, 'A' = 10, ..., 'Z' = 35
        for (i = 0; i < squareLength; i++) {
            for (j = 0; j < squareLength; j++) {
                cin >> c;
                square[i][j] = isdigit(c) ? (c - '0') : (c - 'A' + 10);
            }
        }

        if (isLatinSquare(square)) {
            if (isReducedForm(square))
                cout << "Reduced" << endl;
            else
                cout << "Not Reduced" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}

/*	Checks if a given array represents a Latin Square
    Latin Square is defined as an array such that:
    (1) Elements across leftmost column are unique
    (2) Elements across topmost row are unique
*/
bool isLatinSquare(vector<vector<int>>& arr) {
    set<int> rowSet;
    set<int> colSet;
    int n = arr.size();

    // Check for non-unique characters across leftmost column
    for (int i = 0; i < n; i++)
        if (!rowSet.insert(arr[i][0]).second)
            return false;

    // Check for non-unique characters across topmost row
    for (int j = 0; j < n; j++)
        if (!colSet.insert(arr[0][j]).second)
            return false;

    // Both leftmost column and topmost row each have unique characters
    // Therefore, this array is a Latin square
    return true;
}

/*	Checks if a given array is in reduced form
    An array in reduced form is defined as an array such that:
    (1) Elements across leftmost column are in natural order
    (2) Elements across topmost row are in natural order
*/
bool isReducedForm(vector<vector<int>>& arr) {
    int n = arr.size();

    // Check for non-natural order across leftmost column
    for (int i = 0; i < n; i++)
        if (arr[i][0] != i)
            return false;

    // Check for non-natural order across topmost row
    for (int j = 0; j < n; j++)
        if (arr[0][j] != j)
            return false;

    // Both leftmost column and topmost row are naturally ordered
    // Therefore, this array is reduced
    return true;
}
