// 4435 - Obstacle Course

// Warning! Disgusting O(V^2) Djikstra implementation below

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Graph {
    vector<vector<int>> minDist;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int N;

    Graph(int _N);
    void parseGraph();
    vector<Point> getNeighbors(Point& p);
    void performDjikstra();
    Point getMinDistPoint();
};

int main() {
    int N, problemNum = 1;

    while ((cin >> N) && (N != 0)) {
        Graph g(N);
        g.parseGraph();
        g.performDjikstra();
        cout << "Problem " << problemNum++ << ": " << g.minDist[N - 1][N - 1] << endl;
    }

    return 0;
}

Graph::Graph(int _N) {
    N = _N;
    minDist = vector<vector<int>>(N, vector<int>(N, INF));
    grid = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
}

void Graph::parseGraph() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
}

vector<Point> Graph::getNeighbors(Point& p) {
    vector<Point> neighbors;

    if (p.x > 0)     neighbors.push_back(Point(p.x - 1, p.y));
    if (p.x < N - 1) neighbors.push_back(Point(p.x + 1, p.y));
    if (p.y > 0)     neighbors.push_back(Point(p.x, p.y - 1));
    if (p.y < N - 1) neighbors.push_back(Point(p.x, p.y + 1));

    return neighbors;
}

void Graph::performDjikstra() {
    queue<Point> q;
    q.push(Point(0, 0));
    minDist[0][0] = grid[0][0];

    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        visited[p.x][p.y] = true;

        for (Point n : getNeighbors(p)) {
            if (visited[n.x][n.y])
                continue;

            minDist[n.x][n.y] = min(minDist[n.x][n.y], minDist[p.x][p.y] + grid[n.x][n.y]);
        }

        Point newFront = getMinDistPoint();
        if (newFront.x != -1 && newFront.y != -1)
            q.push(newFront);
    }
}

Point Graph::getMinDistPoint() {
    int currMinDist = INF;
    Point minDistPoint(-1, -1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && minDist[i][j] <= currMinDist)
                currMinDist = minDist[i][j], minDistPoint = Point(i, j);

    return minDistPoint;
}
