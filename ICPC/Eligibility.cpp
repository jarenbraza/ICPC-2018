// 6866 - Eligibility

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, collegeStart, birthdate;
    int coursesTaken, cases;
    cin >> cases;

    while (cases--) {
        cin >> name >> collegeStart >> birthdate >> coursesTaken;
        if ((collegeStart.substr(0, 4) >= "2010") || (birthdate.substr(0, 4) >= "1991"))
            cout << name << " eligible" << endl;
        else if (coursesTaken > 40)
            cout << name << " ineligible" << endl;
        else
            cout << name << " coach petitions" << endl;
    }

    return 0;
}
