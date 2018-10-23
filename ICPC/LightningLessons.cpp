// 5894 - Lightning Lessons

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool hasConverged(vector<int> amps, int start);

int main() {
    int N, M, i, j, cycles, temp;
    string s;
    cin >> N;

    while (N--) {
        cin >> M;
        vector<int> amps(M);
        for (i = 0; i < M; i++)
            cin >> amps[i];

        cycles = 0;
        i = 0;
        while (!hasConverged(amps, i) && i < M) {
            j = M - 1;
            while (j > i) {
                amps[j] -= amps[j - 1];
                j--;
            }
            cycles++;
            i++;
        }

        if (amps[M - 1] == 0) {
            s = "";
            while (cycles--)
                s += 'z';
            s += "ap!";
            cout << s << endl;
        }
        else if (amps[M - 1] > 0)
            cout << "*fizzle*" << endl;
        else
            cout << "*bunny*" << endl;
    }

    return 0;
}

// Check if all amps are zero starting from the given start index
bool hasConverged(vector<int> amps, int start) {
    for (int i = start; i < amps.size(); i++)
        if (amps[i] != 0)
            return false;
    return true;
}
