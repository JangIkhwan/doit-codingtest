/*
23-07-17 19:22 ~
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
int N, K;

vector<int> graph[MAX];
int buildTime[MAX];
int inDegree[MAX];
int minTime[MAX];

void topologicalSort() {
	queue<pair<int, int>> qu;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			qu.push(make_pair(buildTime[i], i));
		}
	}
	while (qu.empty()) {
		int nowTime = qu.front().first;
		int now = qu.front().second;
		qu.pop();
		for (int next : graph[now]) {
			inDegree[next] -= 1;
			int nextTime = nowTime + buildTime[next];
			if (nextTime > minTime[next]) {
				minTime[next] = nextTime;
			}
			if (inDegree[next] == 0) {
				qu.push(make_pair(nowTime + buildTime[next], next));
			}
		}
	}
}

int main(void) {
	int T, x, y, w;
	vector<int> result;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &buildTime[i]);
			minTime[i] = inDegree[i] = 0;
			graph[i].clear();
		}
		for (int i = 1; i <= K; i++) {
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			inDegree[y] += 1;
		}
		scanf("%d", &w);
		topologicalSort();
		result.push_back(minTime[w]);
	}
	for (int t = 0; t < T; t++) {
		printf("%d\n", result[t]);
	}
	return 0;
}