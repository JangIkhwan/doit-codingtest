/*
https://www.acmicpc.net/problem/1753

23-06-12 20:40 ~ 21:10
1차 시도 : 틀림


5 7
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
1 3 1

21:10 ~ 21:42
1차 수정 : 메모리 초과
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 30
using namespace std;

int V, E;
short graph[20001][20001]; // 메모리 초과 원인
int dists[20001];
bool selected[20001];

void dijkstra(int start) {
	int shortestDist;
	int now;
	for (int i = 1; i <= V; i++) {
		dists[i] = INF;
	}
	dists[start] = 0;
	for (int i = 1; i <= V; i++) {
		shortestDist = INF; //
		for (int v = 1; v <= V; v++) {
			if (!selected[v] && dists[v] < shortestDist) {
				now = v;
				shortestDist = dists[v];
			}
		}
		selected[now] = true;
		for (int next = 1; next <= V; next++) {
			if (graph[now][next] <= 0 || selected[next]) continue;
			dists[next] = min(dists[next], dists[now] + graph[now][next]);
		}
	}
}

int main(void) {
	int K, u, v, w;
	bool found;
	cin >> V >> E;
	cin >> K;
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		if (graph[u][v] > 0 && graph[u][v] > w) {
			graph[u][v] = w;
		}
		else {
			graph[u][v] = w;
		}
	}

	dijkstra(K); //

	for (int i = 1; i <= V; i++) {
		if (dists[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dists[i] << "\n";
		}
	}

	return 0;
}