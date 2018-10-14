#include <iostream>
#include <string>
using namespace std;

int main() {
    int i, T, N, ans;
    string S;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        cin >> S;
        S += "##";

        ans = 0;
        for (i = 0; i < N; i++) {
            if (S[i] == '.') {
                S[i] = S[i + 1] = S[i + 2] = '#';
                ans++;
            }
        }

        cout << "Case " << t << ": " << ans << endl;
    }

    return 0;
}
