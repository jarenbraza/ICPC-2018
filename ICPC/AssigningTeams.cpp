// 7886 - Assigning Teams

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B, C, D, bestSkillGap;

    while (cin >> A >> B >> C >> D) {
        vector<int> skillLevels = { A, B, C, D };
        bestSkillGap = INT32_MAX;

        sort(skillLevels.begin(), skillLevels.end());

        do {
            bestSkillGap = min(bestSkillGap, abs(skillLevels[0] + skillLevels[1] - skillLevels[2] - skillLevels[3]));
        } while (next_permutation(skillLevels.begin(), skillLevels.end()));

        cout << bestSkillGap << endl;
    }

    return 0;
}
