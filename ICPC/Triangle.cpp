// 7371 - Triangle

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define NUM_SIDES_IN_TRIANGLE 3

bool areSameTriangle(vector<int>& triangle1, vector<int>& triangle2) {
    return (triangle1[0] == triangle2[0]) && (triangle1[1] == triangle2[1]) && (triangle1[2] == triangle2[2]);
}

bool isPythagoreanTriplet(vector<int>& triangle) {
    return (triangle[0] * triangle[0] + triangle[1] * triangle[1]) == (triangle[2] * triangle[2]);
}

int main() {
    vector<int> triangle1(NUM_SIDES_IN_TRIANGLE);
    vector<int> triangle2(NUM_SIDES_IN_TRIANGLE);

    while (cin >> triangle1[0] >> triangle1[1] >> triangle1[2]) {
        cin >> triangle2[0] >> triangle2[1] >> triangle2[2];
        sort(triangle1.begin(), triangle1.end());
        sort(triangle2.begin(), triangle2.end());
        if (!areSameTriangle(triangle1, triangle2))
            cout << "NO" << endl;
        else if (isPythagoreanTriplet(triangle1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
