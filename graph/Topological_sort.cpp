#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>

using namespace std;

unordered_map<int, vector<int>> adj;
unordered_map<int, int> indegree;
vector<int> topologicalSort(int n) {
	vector<int> ans;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		ans.push_back(tmp);

		for (int v : adj[tmp]) {
			indegree[v]--;
			if (indegree[v] == 0) {
				q.push(v);
			}
		}
	}
	return ans;
}

int main() {
	int numVertex = 6;
	vector<vector<int>> graph = { {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1} };
	for (vector<int> edge : graph) {
		adj[edge[0]].push_back(edge[1]);
		indegree[edge[1]]++;
	}
}

// class Graph {
// public:
// 	int numVertex;
// 	list<int>* adj;
// 	Graph(int n) {
// 		numVertex = n;
// 		adj = new list<int>[n];
// 	}

// 	void addEdge(int x, int y) {
// 		adj[x].push_back(y);
// 		adj[y].push_back(x);
// 	}
// };