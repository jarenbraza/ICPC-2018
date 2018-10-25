// 8047 - Secret Chamber at Mount Rushmore

#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

bool hasFullTranslation(string& originalStr, string& encodedStr, unordered_map<char, list<char>>& adjList);
bool hasTranslation(char a,  char b, unordered_map<char, list<char>>& adjList);

int main() {
    int m, n;
    char a, b;
    string originalStr, encodedStr;

    while (cin >> m >> n) {
        unordered_map<char, list<char>> adjList;
        while (m--) {
            cin >> a >> b;
            adjList[a].push_back(b);
        }
        while (n--) {
            cin >> originalStr >> encodedStr;
            if (hasFullTranslation(originalStr, encodedStr, adjList))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    return 0;
}

bool hasFullTranslation(string& originalStr, string& encodedStr, unordered_map<char, list<char>>& adjList) {
    if (originalStr.length() != encodedStr.length())
        return false;
    
    if (originalStr == encodedStr)
        return true;

    for (int i = 0; i < originalStr.length(); i++) {
        if (originalStr[i] == encodedStr[i])
            continue;

        if (!hasTranslation(originalStr[i], encodedStr[i], adjList))
            return false;
    }

    return true;
}

bool hasTranslation(char a,  char b, unordered_map<char, list<char>>& adjList) {
    bool found = false;
    char c;
    set<char> visited;
    queue<char> q;

    q.push(a);

    while (!q.empty()) {
        c = q.front();
        q.pop();

        if (c == b)
            return true;

        visited.insert(c);

        for (char candidate : adjList[c]) {
            if (visited.find(candidate) != visited.end())
                continue;
            q.push(candidate);
        }
    }

    return false;
}
