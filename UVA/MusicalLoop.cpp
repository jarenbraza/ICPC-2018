// 11496 - Musical Loop

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, i, peaks;

    while ((cin >> N) && (N != 0)) {
        vector<int> loop(N);
        for (i = 0; i < N; i++)
            cin >> loop[i];

        peaks = 0;
        for (i = 0; i < N; i++) {
            if (i == 0) {
                if (loop[0] > loop[N - 1] && loop[0] > loop[1])
                    peaks++;
                else if (loop[0] < loop[N - 1] && loop[0] < loop[1])
                    peaks++;
            }
            else if (i == N - 1) {
                if (loop[N - 1] > loop[N - 2] && loop[N - 1] > loop[0])
                    peaks++;
                else if (loop[N - 1] < loop[N - 2] && loop[N - 1] < loop[0])
                    peaks++;
            }
            else if (loop[i] > loop[i - 1] && loop[i] > loop[i + 1])
                peaks++;
            else if (loop[i] < loop[i - 1] && loop[i] < loop[i + 1])
                peaks++;
        }

        cout << peaks << endl;
    }

    return 0;
}
