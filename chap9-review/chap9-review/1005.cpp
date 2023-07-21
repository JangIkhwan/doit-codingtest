/*
23-07-19 14:37 ~ 15:25 

 1
/ |
2 3
/| |
4 5 6
  |/
  7
  |
  8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int T, N, K, W;

vector<int> graph[MAX];
int inDegree[MAX];
int minTime[MAX];
int buildTime[MAX];

void topologicalSort() {
	queue<int> qu;
	for (int i = 1; i < MAX; i++) {
		if (inDegree[i] == 0) {
			qu.push(i);
		}
	}
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		for (int next : graph[now]) {
			inDegree[next] -= 1;
			minTime[next] = max(minTime[next], minTime[now] + buildTime[next]);
			if (inDegree[next] == 0) {
				qu.push(next);
			}
		}
	}
}

int main(void) {
	int a, b;
	vector<int> result;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &K);
		for (int n = 1; n <= N; n++) {
			scanf("%d", &buildTime[n]);
			minTime[n] = buildTime[n];
		}
		for (int k = 1; k <= K; k++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			inDegree[b] += 1; // 위상정렬 호출 전에 inDegree 초기화해야 함
		}
		scanf("%d", &W);
		topologicalSort();
		result.push_back(minTime[W]);
		for (int n = 1; n <= N; n++) {
			graph[n].clear();
			inDegree[n] = 0; 
		}
	}
	for (int t = 0; t < T; t++) {
		printf("%d\n", result[t]);
	}
	return 0;
}