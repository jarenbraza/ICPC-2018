// 5800 - Repeating Characters

#include <iostream>
#include <string>
using namespace std;

int main() {
    string originalStr, outputStr;
    int P, N, R, r;
    cin >> P;
    
    while (P--) {
        cin >> N >> R >> originalStr;

        outputStr = "";
        for (char c : originalStr)
            for (r = 0; r < R; r++)
                outputStr += c;

        cout << N << " " << outputStr << endl;
    }

    return 0;
}
