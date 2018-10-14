#include <iostream>
#include <set>
using namespace std;

struct Pair {
    int A;
    int B;
    Pair(int _A, int _B) : A(_A), B(_B) {}
};

int main() {
    int A, B, i, n;
    while (cin >> n && n != 0) {
        set<pair<int, int>> s;
        for (i = 0; i < n; i++) {
            cin >> A >> B;
            if (A < B)
                swap(A, B);
            pair<int, int> p = make_pair(A, B);
            if (!s.insert(p).second)
                s.erase(p);
        }
        cout << (s.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}