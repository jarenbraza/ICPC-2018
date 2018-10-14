#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int year;
    int month;
    int day;
};

/*  Compares ages of two people
    Returns 1 if A older than B, or -1 if A younger than B
*/
int compareAges(Person& A, Person& B) {
    if ((A.year < B.year) || (A.year == B.year && A.month < B.month) || (A.year == B.year && A.month == B.month && A.day < B.day))
        return 1;
    
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<Person> people(n);

    for (int i = 0; i < n; i++) {
        cin >> people[i].name;
        cin >> people[i].day >> people[i].month >> people[i].year;
    }

    Person youngestPerson = people[0];
    Person oldestPerson = people[0];

    for (int i = 1; i < n; i++) {
        Person person = people[i];
        if (compareAges(person, youngestPerson) == -1)
            youngestPerson = person;
        if (compareAges(person, oldestPerson) == 1)
            oldestPerson = person;
    }

    cout << youngestPerson.name << endl;
    cout << oldestPerson.name << endl;

    return 0;
}
