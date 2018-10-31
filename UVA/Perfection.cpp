// 382 - Perfection

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int isPerfect(int N) {
    int sum = 0;

    for (int i = 1; i <= N / 2; i++)
        if (N % i == 0)
            sum += i;

    if (sum < N)
        return -1;

    if (sum > N)
        return 1;

    return 0;
}

string getStr(int N) {
    string s = to_string(N);
    while (s.length() != 5)
        s = " " + s;
    return s;
}

int main() {
    int N, result;

    cout << "PERFECTION OUTPUT" << endl;
    while ((cin >> N) && (N != 0)) {
        result = isPerfect(N);
        if (result == -1)
            cout << getStr(N) << "  DEFICIENT" << endl;
        else if (result == 0)
            cout << getStr(N) << "  PERFECT" << endl;
        else
            cout << getStr(N) << "  ABUNDANT" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
