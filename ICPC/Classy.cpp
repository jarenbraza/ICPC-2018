#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    stack<string> ranks;
    size_t sum = 0;
};

int main() {
    string rank;
    int i, j, n, maxRankLength;

    while (cin >> n) {
        vector<Person> people(n);

        // Read in all people and set the most amount of ranks someone has
        maxRankLength = 0;
        for (i = 0; i < n; i++) {
            // Read in name of this person, removing the colon
            cin >> people[i].name;
            people[i].name.pop_back();

            while ((cin >> rank) && (rank != "class"))
                people[i].ranks.push(rank);
            
            maxRankLength = max(maxRankLength, (int)people[i].ranks.size());
        }

        // Find ranking sum for each person
        for (i = 0; i < n; i++) {
            for (j = 0; j < maxRankLength; j++){
                // If no more ranks, assume "middle" rank for adjusting sum
                if (people[i].ranks.empty())
                    people[i].sum = people[i].sum * 3 + 1;
                    
                // Otherwise, adjust sum using current rank
                else {
                    // Get current rank
                    rank = people[i].ranks.top();
                    people[i].ranks.pop();

                    // Adjust sum based on this rank
                    people[i].sum = people[i].sum * 3 + (rank == "lower" ? 0 : (rank == "middle" ? 1 : 2));
                }
            }
        }

        // Sort people by ranking sum
        // If sums are equal, sort by name
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (people[j].sum < people[j + 1].sum)
                    swap(people[j], people[j + 1]);
                else if (people[j].sum == people[j + 1].sum && people[j].name > people[j + 1].name)
                    swap(people[j], people[j + 1]);
            }
        }

        // Output sorted results
        for (i = 0; i < n; i++)
            cout << people[i].name << endl;
    }

    return 0;
}