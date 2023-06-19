/*
https://www.acmicpc.net/problem/1219

23-06-15 16:42~ 17:44
1차 시도 : 틀림.

힌트 참고 : 맞음.

생각하지 못한 점
- 사이클이 존재하더라도 시작점에서 도착점 사이에 없다면 예외가 아니므로 돈의값을 출력해야 함.
- 나는 사이클이 존재하면 무조건 gg를 출력하도록 만들어서 틀렸던 것임.

기억할 점
- 도착점이 사이클에 포함되는지 확인하는 방법은 2가지가 있음
- 첫번째는 벨만포드의 for문을 정점의 개수만큼 더 수행해서 사이클에 들어가는 정점을 찾는 것임.
- 두번째는 for문이 N번째 수행되었을 때 갱신된 정점을 시작점으로 bfs를 수행하는 것임.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct Edge {
	int start, end, cost;
};

long long INF = LLONG_MAX; //

int N, M;
vector<Edge> graph;
long long dists[50]; //
bool belongToCycle[50];

void bellmanFord(int s) {
	for (int i = 0; i < N; i++) {
		dists[i] = INF;
	}
	dists[s] = 0;
	for (int i = 0; i < 2 * N; i++) {
		for (Edge edge : graph) {
			int start = edge.start;
			int end = edge.end;
			int cost = edge.cost;
			if (belongToCycle[start]) {
				belongToCycle[end] = true;
				continue;
			}
			if (dists[start] != INF && dists[end] > dists[start] + cost) {
				dists[end] = dists[start] + cost;
				if (i >= N - 1) { 
					belongToCycle[end] = true;
				}
			}
		}
	}
}

int main(void) {
	int src, dst, s, e, c;
	int profit[50];
	scanf("%d %d %d %d", &N, &src, &dst, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &c);
		graph.push_back({ s, e, c });
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &profit[i]);
	}
	for (Edge& edge : graph) {
		edge.cost = edge.cost - profit[edge.end];
	}

	bellmanFord(src);

	if (dists[dst] == INF) {
		printf("gg\n");
	}
	else{
		if (belongToCycle[dst]) {
			printf("Gee\n");
		}
		else {
			printf("%lld\n", -dists[dst] + profit[src]); //
		}
	}

	return 0;
}

//struct Edge {
//	int start, end, cost;
//};
//
//long long INF = LLONG_MAX; //
//
//int N, M;
//vector<Edge> graph;
//long long path[50]; //
//vector<int> cycle;
//
//bool bellmanFord(int s) {
//	for (int i = 0; i < N; i++) {
//		path[i] = INF;
//	}
//	path[s] = 0;
//	bool hasNegCycle = false;
//	for (int i = 0; i < N; i++) {
//		for (Edge edge : graph) {
//			int start = edge.start;
//			int end = edge.end;
//			int cost = edge.cost;
//			if (path[start] != INF && path[end] > path[start] + cost) {
//				path[end] = path[start] + cost;
//				if (i == N - 1) {
//					hasNegCycle = true;
//				}
//			}
//		}
//	}
//	return hasNegCycle;
//}
