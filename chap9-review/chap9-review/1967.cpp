/*
https://www.acmicpc.net/problem/1967

23-07-22 21:11 ~ 21:46
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[10001];
int dists[10001];
bool visited[10001];

void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i].first;
		int dist = tree[now][i].second;
		if (!visited[next]) {
			dists[next] = dists[now] + dist;
			dfs(next);
		}
	}
}

int main(void) {
	int N;
	int s, e, d;
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d %d", &s, &e, &d);
		tree[s].push_back({ e, d });
		tree[e].push_back({ s, d });
	}
	dfs(1);
	int maxDist = dists[1];
	int onePoint = 1;
	for (int i = 2; i <= N; i++) {
		if (dists[i] > maxDist) {
			maxDist = dists[i];
			onePoint = i;
		}
	}
	memset(dists, 0, sizeof(dists));
	memset(visited, 0, sizeof(visited));
	dfs(onePoint);
	maxDist = dists[1];
	for (int i = 2; i <= N; i++) {
		if (dists[i] > maxDist) {
			maxDist = dists[i];
		}
	}
	printf("%d\n", maxDist);
	return 0;
}
