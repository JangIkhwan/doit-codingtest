/*
https://www.acmicpc.net/problem/1865
23-07-21 11:29 ~ 

����� ������ �ð��� �ǵ��� ���� ��찡 �ִ��� ���ϱ�
-> ���ǻ���Ŭ�� ���� ���� Ȯ���ϱ�
-> ���� ����� ���� ����Ŭ�� Ȯ��
�׷����� ����׷���
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

const long long INF = 12500000001; // 

vector<Edge> edgeList;
long long dist[501]; //

bool bellmanFord() {
	bool hasCycle = false;
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
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
			edgeList.push_back({ s, e, -t });
		}
		for (int i = 2; i <= N; i++) { // 
			dist[i] = INF;
		}
		bool hasCycle = bellmanFord();
		if (hasCycle) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		edgeList.clear(); // 
	}
	return 0;
}


bool visited[501];
vector<int> graph[501];

void dfs(int now) {
	visited[now] = true;
	for (int next : graph[now]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}
