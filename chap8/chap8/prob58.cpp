/*
23-06-14 16:37 ~ 59
1차 시도 : 출력 초과 

17:27 
힌트 보고 수정
- 출력 초과 이유를 모르겠어서 질문게시판을 찾아봄
- 이 문제에서는 언더플로우에 주의해야 함. 
경로의 길이가 6000만 x 500으로 커질 수 있음
- INF는 경로값을 변경할지 결정할 때만 사용됨. 
가능한 경로값의 최대보다 커야하는데, 이번에는 운이 좋아서 통과된 것으로 보임.
- https://www.acmicpc.net/board/view/55270
- https://www.acmicpc.net/board/view/91430
- https://www.acmicpc.net/board/view/84267#comment-137025

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int start, end, cost;
};

int INF = 987654321; // INF는 경로의 최대값보다 커야 함.

int N, M;
vector<Edge> graph;
long long path[501]; // 언더플로우가 발생할 수 있기 때문에 long long을 사용해야 함.

bool bellmanFord(int start) {
	bool hasNegCycle = false;
	for (int i = 1; i <= N; i++) {
		path[i] = INF;
	}
	path[start] = 0;
	for (int i = 1; i <= N; i++) {
		for (Edge edge : graph) {
			int start = edge.start;
			int end = edge.end;
			int cost = edge.cost;
			if (path[start] != INF && path[end] > path[start] + cost) {
				path[end] = path[start] + cost;
				if (i == N) hasNegCycle = true;
			}
		}
	}
	return hasNegCycle;
}

int main(void) {
	int start, end, cost;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		graph.push_back({ start, end, cost });
	}

	if (bellmanFord(1)) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (path[i] == INF) {
				printf("-1\n");
			}
			else {
				printf("%d\n", path[i]);
			}
		}
	}
	return 0;
}
