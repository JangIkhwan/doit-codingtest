/*
23-07-21 22:43

음의 사이클이 존재하는지 확인해야 함

참고: 
https://www.acmicpc.net/board/view/50494

시간 초과 실패
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
	int start, end, weight;
};

int TC, N, M, W;

const int INF = 5000001;

int dist[501];
vector<Edge> edgeList;

bool bellmanFord(int start) {
	bool hasCycle = false;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	for (int i = 1; i <= N; i++) { //
		for (const Edge& edge : edgeList) {
			int s = edge.start;
			int e = edge.end;
			int w = edge.weight;
			if (dist[s] != INF && dist[s] + w < dist[e]) {
				dist[e] = dist[s] + w;
				if (i >= N) {
					hasCycle = true;
				}
			}
		}
	}
	return hasCycle;
}

int main(void) {
	int s, e, t;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d %d", &N, &M, &W);
		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d", &s, &e, &t);
			edgeList.push_back({ s, e, t });
			edgeList.push_back({ e, s, t });
		}
		for (int i = 1; i <= W; i++) {
			scanf("%d %d %d", &s, &e, &t);
			edgeList.push_back({ s, e, -t }); //
		}
		bool hasCycle = false;
		for (int start = 1; start <= N; start++) { //
			if (bellmanFord(start)) {
				hasCycle = true;
			}
		}
		if (hasCycle) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		edgeList.clear();
	}
	return 0;
}
