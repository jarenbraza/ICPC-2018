#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int V, a, b, i;
    bool isBipartite;

    while ((cin >> V) && (V != 0)) {
        vector<vector<int>> graph(V);
        queue<int> q;        

        while ((cin >> a >> b) && (a != 0) && (b != 0)) {
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }

        q.push(0);
        vector<int> color(V, -1);
        isBipartite = true;

        while (!q.empty() && isBipartite) {
            a = q.front();
            q.pop();
            for (i = 0; i < (int)graph[a].size(); i++) {
                b = graph[a][i];
                if (color[b] == -1) {
                    color[b] = color[a] == 0 ? 1 : 0;
                    q.push(b);
                }
                else if (color[b] == color[a]) {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << endl;
    }

    return 0;
}