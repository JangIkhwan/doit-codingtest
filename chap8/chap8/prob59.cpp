/*
23-06-19 16:10

Âü°í 
- https://nahwasa.com/entry/%EC%9E%90%EB%B0%94-%EB%B0%B1%EC%A4%80-1854-K%EB%B2%88%EC%A7%B8-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C-%EC%B0%BE%EA%B8%B0
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int INF = INT_MAX;

int N, M, K;
vector<pair<int, int>> graph[1001];
priority_queue<int> path[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (auto edge : graph[now]) {
			int next = edge.first;
			int nextDist = dist + edge.second;
			if (path[next].size() < K) {
				path[next].push(nextDist);
				pq.push(make_pair(-nextDist, next));
			}
			else if (nextDist < path[next].top()){
				path[next].pop();
				path[next].push(nextDist);
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

int main(void) {
	int s, e, c;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &s, &e, &c);
		graph[s].push_back(make_pair(e, c));
	}

	dijkstra(1);

	for (int i = 1; i <= N; i++) {
		if (path[i].size() == K) {
			printf("%d\n", path[i].top());
		}
		else {
			printf("-1\n");
		}
	}

	return 0;
}