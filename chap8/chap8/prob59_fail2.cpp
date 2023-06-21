/*
https://www.acmicpc.net/problem/1854

23-06-19 11:35
풀이시간 40분 초과로 실패
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int INF = INT_MAX; // 오버플로우??

int N, M, K;
vector<pair<int, int>> graph[1001];
int dists[1001];
vector<int> path[1001];


void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= N; i++) {
		dists[i] = INF;
	}
	dists[start] = 0;
	pq.push(make_pair(0, start));
	for (int i = 1; i <= N; i++) {
		pq.push(make_pair(-path[i].back(), i));
	}
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dists[now] < dist || dist == -1) continue;

		for (auto edge : graph[now]) {
			int next = edge.first;
			int nextDist = dists[now] + edge.second;
			if (nextDist > path[next].back() && nextDist < dists[next]) {
				dists[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

void findKthPath() {
	for (int i = 1; i <= N; i++) {
		path[i].push_back(-1);
	}
	for (int i = 1; i <= K; i++) {
		//cout << i << "\n";

		dijkstra(1);
		for (int j = 1; j <= N; j++) {
			cout << dists[j] << " ";

			if ((j == 1 && (i == 1 || dists[j] > 0)) || (j > 1 && dists[j] != INF)) {
				path[j].push_back(dists[j]);
			}
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		if (path[i].size() > K) {
			printf("%d\n", path[i][K]);
		}
		else {
			printf("-1\n");
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

	findKthPath();

	return 0;
}