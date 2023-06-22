/*
https://www.acmicpc.net/problem/17472

23-06-22 21:55 ~ 23:13
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int weight, v1, v2;
	bool operator < (const Edge tg) const {
		return weight > tg.weight;
	}
};

class DisjointSet {
	int parents[7];
public:
	DisjointSet() {
		for (int i = 1; i <= 6; i++) {
			parents[i] = i;
		}
	}
	void merge(int i, int j) {
		int u = find(i);
		int v = find(j);
		if (u != v) {
			parents[u] = v;
		}
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
	
};

int N, M, V;
int country[11][11];
bool visited[11][11];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
priority_queue<Edge> pq;

int Kruskal() {
	DisjointSet set;
	int treeWeight = 0;
	int edgeCount = 0;
	while (edgeCount < V - 1) {
		if (pq.empty()) {
			return -1;
		}
		int weight = pq.top().weight;
		int v1 = pq.top().v1;
		int v2 = pq.top().v2;
		//cout << "(" << v1 << ", " << v2 << ") : " << weight << "\n";
 		pq.pop();
		if (set.find(v1) != set.find(v2)) {
			set.merge(v1, v2);
			treeWeight += weight;
			edgeCount += 1;
		}
	}
	if (edgeCount == V - 1) {
		return treeWeight;
	}
	else {
		return -1;
	}
}

void dfs(int y, int x, int n) {
	visited[y][x] = true;
	country[y][x] = n;
	for (int direct = 0; direct < 4; direct++) { //
		int newX = x + dx[direct];
		int newY = y + dy[direct];
		if (newX > M || newX < 1 || newY < 1 || newY > N) continue;
		if(country[newY][newX] > 0 && !visited[newY][newX]) {
			dfs(newY, newX, n);
		}
	}
}

void convertToGraph() {
	V = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (country[y][x] > 0 && !visited[y][x]) {
				V += 1;
				dfs(y, x, V);
			}
		}
	}
	int start, end, length;
	bool startsAtIsland;
	for (int y = 1; y <= N; y++) {
		length = 0;
		startsAtIsland = false;
		for (int x = 1; x <= M; x++) {
			if (country[y][x] > 0) {
				if (length >= 2) {
					end = country[y][x];
					pq.push({ length, start, end });
				}
				start = country[y][x];
				startsAtIsland = true;
				length = 0;
			}
			if (startsAtIsland && country[y][x] == 0) {
				length += 1;
			}
		}
	}
	for (int x = 1; x <= M; x++) {
		length = 0;
		startsAtIsland = false;
		for (int y = 1; y <= N; y++) {
			if (country[y][x] > 0) {
				if (length >= 2) {
					end = country[y][x];
					pq.push({ length, start, end });
				}
				start = country[y][x];
				startsAtIsland = true;
				length = 0;
			}
			if (startsAtIsland && country[y][x] == 0) {
				length += 1;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%d", &country[y][x]);
		}
	}

	convertToGraph();

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << country[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/


	printf("%d\n", Kruskal());

	return 0;
}