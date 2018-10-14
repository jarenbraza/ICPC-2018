#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int a, b, i, n, e;
	bool isBicolorable;

	while ((cin >> n) && (n != 0) && (cin >> e)) {
		vector<list<int>> adjList(n, list<int>());
		queue<int> q;

		for (i = 0; i < e; i++) {
			cin >> a >> b;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}

		q.push(0);
		vector<int> color(n, -1);
		color[0] = 0;

		isBicolorable = true;
		while (!q.empty() && isBicolorable) {
			a = q.front();
			q.pop();
			for (int node : adjList[a]) {
				if (color[node] == -1) {
					color[node] = (color[a] == 0) ? 1 : 0;
					q.push(node);
				}
				else if (color[node] == color[a]) {
					isBicolorable = false;
					break;
				}
			}
		}

		if (isBicolorable)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}

	return 0;
}
