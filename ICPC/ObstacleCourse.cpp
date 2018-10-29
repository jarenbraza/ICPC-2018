// 4435 - Obstacle Course

// Warning! Disgusting O(V^2) Djikstra implementation below
// At the time, could not figure out how to make an STL priority queue with removable keys

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Weights range from 0-9, and there will be at most 125x125 = 15625 vertices
// So, this is an sufficiently large INF for Djikstra min-distance grid initialization
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
    // Start from top-left corner
    Point p(0, 0);
    minDist[0][0] = grid[0][0];

    // Process each vertex
    // Point (-1, -1) is special case that appears when all vertices have been visited 
    while ((p.x != -1) && (p.y != -1)) {
        visited[p.x][p.y] = true;

        // Update distance of neighbors for current vertex
        for (Point n : getNeighbors(p)) {
            if (visited[n.x][n.y])
                continue;

            minDist[n.x][n.y] = min(minDist[n.x][n.y], minDist[p.x][p.y] + grid[n.x][n.y]);
        }

        // Process point with next smallest distance that is unvisited
        p = getMinDistPoint();
    }
}

Point Graph::getMinDistPoint() {
    int currMinDist = INF;
    Point minDistPoint(-1, -1);

    // Finds unvisited point of minimal distance
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && minDist[i][j] <= currMinDist)
                currMinDist = minDist[i][j], minDistPoint = Point(i, j);

    return minDistPoint;
}
