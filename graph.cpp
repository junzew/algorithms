#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define VISITED 1
#define UNVISITED 0
#define INF 100000000
using namespace std;

vector<vector<int>> AdjList; // Adjacency List

vector<int> d; // distance to source s
queue<int> q;
void bfs(int s) {
	d[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		cout << u << " d = " << d[u] << endl;
		for (int i = 0; i < AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			if (d[v] == INF) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

vector<int> Explored; // Explored nodes
void dfs(int u) {
	cout << u << " ";
	Explored[u] = VISITED; // Mark u as VISITED
	for (int i = 0; i < AdjList[u].size(); i++) {// For each connected node v
		int v = AdjList[u][i];
		if (Explored[v] == UNVISITED) {
			dfs(v); // recursively call dfs on UNVISITED nodes
		}
	}
}

/*
Input format:
The first line contains two numbers N, the number of nodes, and the source node index S.
The next N lines contains the connectivity information for each node
The first number c in the is the number of connected nodes to the node.
The following c numbers are the indicies of connected nodes.

3----4 ---- 5
|    |      |
1----2      6
\    /
 \  /
  0

7--8--9

Sample Input:
7 3
2 1 2
3 0 2 3
3 0 1 4
2 1 4
3 2 3 5
2 4 6
0


10 3
2 1 2
3 0 2 3
3 0 1 4
2 1 4
3 2 3 5
2 4 6
0
1 8
2 7 9
1 8
*/
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		Explored.push_back(UNVISITED);
		d.push_back(INF);
	}
	for (int i = 0; i < n; i++) {
		int c, v;
		cin >> c;
		std::vector<int> l;
		for (int j = 0; j < c; j++) {
			cin >> v;
			l.push_back(v);
		}
		AdjList.push_back(l);
	}
	cout << "DFS:";
	dfs(s);
	cout << endl;

	cout << "BFS:" << endl;
	bfs(s);

	cout << "All Connected Components: " << endl;
	int numCC = 0; // number of connected components
	Explored.assign(n, UNVISITED); // sets all vertices’ state to UNVISITED
	for (int i = 0; i < n; i++) // for each vertex i in [0..V-1]
		if (Explored[i] == UNVISITED) // if vertex i is not visited yet
		printf("CC %d: ", ++numCC), dfs(i), printf("\n");
	return 0;
}