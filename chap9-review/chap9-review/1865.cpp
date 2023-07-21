/*
참고:
https://www.acmicpc.net/board/view/50494

기억하기
- 벨만포드는 한 정점에서 다른 정점들까자의 최단 거리를 구할 때 사용할 수 있음.
이떼 INF 값은 도달 가능 여부를 판단하기 위해서 사용함
- 그런데 사이클이 있는지 여부를 판단할 때, 최단거리를 구하는 코드를 그대로 사용하면
사이클과 연결되지 않는 노드부터 시작할 수 있음. 그렇게 되면 사이클을 탐지하지 못함.
- 그래서 사이클이 있는지 여부만 판단할 때는 dist값이 INF인지 판단할 필요가 없음.
- 모든 노드를 시작점으로 하여서 벨만포드를 수행하는 방법도 있으나 시간초과가 발생할 수 있음.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
	int start, end, weight;
};

int TC, N, M, W;

int dist[501];
vector<Edge> edgeList;

bool bellmanFord() {
	bool hasCycle = false;
	for (int i = 1; i <= N; i++) {
		dist[i] = 0;
	}
	for (int i = 1; i <= N; i++) { //
		for (const Edge& edge : edgeList) {
			int s = edge.start;
			int e = edge.end;
			int w = edge.weight;
			if (dist[s] + w < dist[e]) {
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
		bool hasCycle = bellmanFord();
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
