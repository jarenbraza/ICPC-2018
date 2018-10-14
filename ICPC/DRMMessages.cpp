#include <iostream>
#include <string>
using namespace std;

int main() {
    string message, result;
    int i, n, offset;

    while (cin >> message) {
        n = message.length();
        result = string(n / 2, ' ');

        // Rotate first half
        offset = 0;
        for (i = 0; i < n / 2; i++)
            offset = (offset + message[i] - 'A') % 26;
        for (i = 0; i < n / 2; i++)
            message[i] = (message[i] - 'A' + offset) % 26 + 'A';

        // Rotate second half
        offset = 0;
        for (i = n / 2; i < n; i++)
            offset = (offset + message[i] - 'A') % 26;
        for (i = n / 2; i < n; i++)
            message[i] = (message[i] - 'A' + offset) % 26 + 'A';

        // Merge halves into resultant string
        for (i = 0; i < n / 2; i++)
            result[i] = (message[i] - 'A' + message[i + n / 2] - 'A') % 26 + 'A';

        cout << result << endl;
    }

    return 0;
}