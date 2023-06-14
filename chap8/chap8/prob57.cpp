/*
https://www.acmicpc.net/problem/1916

23-06-14 15:30 ~ 15:50
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 987654321;

int N, M;
vector<pair<int, int>> bus[1001];
int minCost[1001];

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		minCost[i] = INF;
	}
	minCost[start] = 0;
	priority_queue<pair<int, int>> qu;
	qu.push(make_pair(0, start)); //
	while (!qu.empty()) {
		int cost = -qu.top().first;
		int now = qu.top().second;
		qu.pop();
		if (minCost[now] < cost) continue;
		for (int i = 0; i < bus[now].size(); i++) {
			int next = bus[now][i].first;
			int nextCost = minCost[now] + bus[now][i].second;
			if (nextCost < minCost[next]) {
				minCost[next] = nextCost;
				qu.push(make_pair(-nextCost, next));
			}
		}
	}
}

int main(void) {
	int s, e, cost;
	int start, end;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &s, &e, &cost);
		bus[s].push_back(make_pair(e, cost));
	}
	scanf("%d %d", &start, &end);

	dijkstra(start);

	printf("%d\n", minCost[end]);
}
