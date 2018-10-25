// 7372 - Excellence

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INF 1e7

int main() {
    int N, i, minRating;

    while (cin >> N) {
        vector<int> ratings(N);

        for (int i = 0; i < N; i++)
            cin >> ratings[i];

        sort(ratings.begin(), ratings.end());

        minRating = INF;
        for (int i = 0; i < N / 2; i++)
            minRating = min(minRating, ratings[N - i - 1] + ratings[i]);
        
        cout << minRating << endl;
    }

    return 0;
}
