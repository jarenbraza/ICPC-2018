// 5739 - User Names

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char getFirst(string& name);
string getLast(string& name);
void insertIntoList(vector<string>& names, string& username, int maxLen);

int main() {
    int numNames, maxLen, testcase = 1;
    char firstInitial;
    string name, lastName, username;

    while ((cin >> numNames >> maxLen) && (numNames != 0 && maxLen != 0)) {
        vector<string> names;
        getchar();
        while (numNames--) {
            getline(cin, name);
            firstInitial = getFirst(name);
            lastName = getLast(name);
            username = firstInitial + lastName.substr(0, min((int)lastName.length(), maxLen - 1));
            insertIntoList(names, username, maxLen);
        }
        cout << "Case " << testcase++ << endl;
        for (string n : names)
            cout << n << endl;
    }

    return 0;
}

char getFirst(string& name) {
    int i = 0;
    while (i < name.length() && !isalpha(name[i]))
        i++;
    return tolower(name[i]);
}

string getLast(string& name) {
    string lastName = "";
    for (int i = name.length() - 1; i >= 0 && name[i] != ' '; i--) {
        if (!isalpha(name[i]))
            continue;
        lastName += tolower(name[i]);
    }
    reverse(lastName.begin(), lastName.end());
    return lastName;
}

// HARDCODED WOOHOO
void insertIntoList(vector<string>& names, string& username, int maxLen) {
    int len = username.length();
    if (find(names.begin(), names.end(), username) == names.end())
        names.push_back(username);
    else {
        bool hasInserted = false;
        for (int i = 1; i <= 9; i++) {
            if (len == maxLen) {
                username[len - 1] = i + '0';
                if (find(names.begin(), names.end(), username) == names.end()) {
                    names.push_back(username);
                    hasInserted = true;
                    break;
                }
            }
            else {
                username.push_back(i + '0');
                if (find(names.begin(), names.end(), username) == names.end()) {
                    names.push_back(username);
                    hasInserted = true;
                    break;
                }
                username.pop_back();
            }
        }

        if (!hasInserted) {
            for (int i = 10; i <= 99; i++) {
                if (len == maxLen) {
                    username[len - 2] = i / 10 + '0';
                    username[len - 1] = i % 10 + '0';
                    if (find(names.begin(), names.end(), username) == names.end()) {
                        names.push_back(username);
                        break;
                    }
                }
                else if (len == maxLen - 1) {
                    username[len - 1] = i / 10 + '0';
                    username.push_back(i % 10 + '0');
                    if (find(names.begin(), names.end(), username) == names.end()) {
                        names.push_back(username);
                        break;
                    }
                    username.pop_back();
                }
                else {
                    username.push_back(i / 10 + '0');
                    username.push_back(i % 10 + '0');
                    if (find(names.begin(), names.end(), username) == names.end()) {
                        names.push_back(username);
                        break;
                    }
                    username.pop_back();
                    username.pop_back();
                }
            }
        }
    }
}
