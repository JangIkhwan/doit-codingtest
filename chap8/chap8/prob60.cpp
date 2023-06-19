/*
https://www.acmicpc.net/problem/1219

23-06-15 16:42~ 17:44
1�� �õ� : Ʋ��.

��Ʈ ���� : ����.

�������� ���� ��
- ����Ŭ�� �����ϴ��� ���������� ������ ���̿� ���ٸ� ���ܰ� �ƴϹǷ� ���ǰ��� ����ؾ� ��.
- ���� ����Ŭ�� �����ϸ� ������ gg�� ����ϵ��� ���� Ʋ�ȴ� ����.

����� ��
- �������� ����Ŭ�� ���ԵǴ��� Ȯ���ϴ� ����� 2������ ����
- ù��°�� ���������� for���� ������ ������ŭ �� �����ؼ� ����Ŭ�� ���� ������ ã�� ����.
- �ι�°�� for���� N��° ����Ǿ��� �� ���ŵ� ������ ���������� bfs�� �����ϴ� ����.
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
