// 8187 - Matrix Multiplication

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ll;

struct Matrix {
    ll L, R;
};

void parseLine(vector<Matrix>& matrices, string& s);

int main() {
    string line;

    while (cin >> line) {
        // Generate matrices from input
        vector<Matrix> matrices;
        parseLine(matrices, line);

        // Create memoization
        int N = matrices.size();
        vector<ll> dp(N, 0);

        for (int k = 1; k < N - 1; k++)
            for (int i = 0; i < N - k; i++)
                dp[i] = min(dp[i], dp[i + 1]) + (matrices[i].L * matrices[i + k].R);

        ll minSpace = min(dp[0], dp[1]);
        cout << minSpace << endl;
    }

    return 0;
}

void parseLine(vector<Matrix>& matrices, string& s) {
    size_t leftBracketIdx, commaIdx, rightBracketIdx;

    // Parse matrices from the string
    leftBracketIdx = s.find_first_of('[');
    while (leftBracketIdx != string::npos) {
        commaIdx = s.find_first_of(',', leftBracketIdx);
        rightBracketIdx = s.find_first_of(']', commaIdx);

        // Generate matrix from what was parsed
        Matrix matrix;
        matrix.L = stoi(s.substr(leftBracketIdx + 1, commaIdx - leftBracketIdx - 1));
        matrix.R = stoi(s.substr(commaIdx + 1, commaIdx - rightBracketIdx - 1));
        matrices.push_back(matrix);

        // Start up parsing again
        leftBracketIdx = s.find_first_of('[', rightBracketIdx);
    }
}
