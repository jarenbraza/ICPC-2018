// 7374 - Racing isoTriangles

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// Isosceles triangle representations of leftmost and rightmost starting positions to obtain a gem
struct IsoTriangle {
    ll L, R;
    bool operator<(const IsoTriangle& rhs) const {
        return (L > rhs.L) || (L == rhs.L && R < rhs.R);
    }
};

int main() {
    ll n, r, w, h, i, x, y, numGems, rightEndpoint;

    while (cin >> n >> r >> w >> h) {
        // Holds the minimal rightmost point for capturing 0 to N-1 gems
        vector<ll> rightEnd(n);

        // Generate isosceles triangles based on scaled grid
        // Scale horizontally by r to avoid decimal calculation for v/r
        vector<IsoTriangle> isoTriangles(n);
        for (i = 0; i < n; i++) {
            cin >> x >> y;
            isoTriangles[i].L = r * x - y; // Leftmost point that i'th gem can still be reached
            isoTriangles[i].R = r * x + y; // Rightmost point that i'th gem can still be reached
        }

        // Sort leftmost points in descending order, breaking ties with ascending order for rightmost points
        sort(isoTriangles.begin(), isoTriangles.end());

        // Assume that capturing the first gem results in the best isosceles triangle for obtaining a gem
        rightEnd[0] = isoTriangles[0].R;
        numGems = 1;

        for (ll i = 1; i < n; i++) {
            rightEndpoint = isoTriangles[i].R;

            // Can immediate add if the right endpoint corresponding to the current gem is at least equal to best case for previous gem count
            // Reason is that the loop is going in order of leftmost points, meaning Best(L) <= Current(L), and Best(R) >= Current(R)
            // That means that the triangle corresponding to the current gem contains the endpoints for the best way to get the previous gem count
            if (rightEndpoint >= rightEnd[numGems - 1]) {
                rightEnd[numGems] = rightEndpoint;
                numGems++;
            }
            // Otherwise, MUST binary search to first case where Best(R) >= Current(R) for some best way to get to a particular gem count
            // Cannot do linear scan as number of gems can be up to 10^5
            else {
                ll L = 0;
                ll R = numGems - 1;
                while (L <= R) {
                    ll M = (L + R) / 2;
                    if (rightEnd[M] < rightEndpoint)
                        L = M + 1;
                    else
                        R = M - 1;
                }

                // L representing the number of gems that can be obtained for this right endpoint
                rightEnd[L] = rightEndpoint;
            }
        }

        cout << numGems << endl;
    }

    return 0;
}
