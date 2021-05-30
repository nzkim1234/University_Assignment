#include <iostream>
#include <vector>
using namespace std;

int n, m;
int s, e;
int* visited;
int* turret;
int turret_num;
vector<vector<int>> adjArray;
void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}

void printGraph() {
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j = 0; j < adjArray[i].size(); j++)
			cout << adjArray[i][j] << " ";
		cout << endl;
	}
}

void aDFS_List(vector<vector<int>> g, int v) {
	visited[v] = 1;
	if (g[v].size() == 1 && v != 1) {
		if (turret[g[v][0]] == 0) {
			turret[v] = 1;
		}
	}
	else if (g[v].size() == 0) {
		turret[v] = 1;
	}
	else {
		for (int i = 1; i < g[v].size(); i++) {
			if (visited[g[v][i]] == 0) {
				aDFS_List(g, g[v][i]);
			}
			if (turret[g[v][i]] == 2) {
				turret[v] = 1;
			}
			else if (turret[g[v][i]] == 1) {
				turret[v] = 2;
			}
			else if (turret[g[v][i]] == 0) {
				turret[v] = 1;
			}
		}
	}

}

void DFS_List(vector<vector<int>> g) {
	visited = new int[g.size()];
	turret = new int[g.size()];
	for (int i = 1; i <= g.size(); i++) {
		visited[i] = 0;
		turret[i] = 0;
	}
	for (int i = 1; i < g.size(); i++) {
		if (visited[i] == 0) {
			aDFS_List(g, i);
		}
	}
}

int main() {
	int Ncase;
	cin >> Ncase;
	for (int i = 0; i < Ncase; i++) {
		adjArray.clear();
		cin >> n >> m;
		adjArray.resize(n + 1);
		turret_num = 0;
		for (int j = 0; j < m; j++) {
			cin >> s >> e;
			AddEdge(s, e);
		}
		DFS_List(adjArray);
		for (int i = 1; i <= n; i++) {
			if (turret[i] == 1)
				turret_num++;
		}
		cout << "\t °á°ú:" << turret_num << endl;
	}
}