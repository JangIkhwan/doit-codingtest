/*
23-06-14 16:37 ~ 59
1�� �õ� : ��� �ʰ� 

17:27 
��Ʈ ���� ����
- ��� �ʰ� ������ �𸣰ھ �����Խ����� ã�ƺ�
- �� ���������� ����÷ο쿡 �����ؾ� ��. 
����� ���̰� 6000�� x 500���� Ŀ�� �� ����
- INF�� ��ΰ��� �������� ������ ���� ����. 
������ ��ΰ��� �ִ뺸�� Ŀ���ϴµ�, �̹����� ���� ���Ƽ� ����� ������ ����.
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

int INF = 987654321; // INF�� ����� �ִ밪���� Ŀ�� ��.

int N, M;
vector<Edge> graph;
long long path[501]; // ����÷ο찡 �߻��� �� �ֱ� ������ long long�� ����ؾ� ��.

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
