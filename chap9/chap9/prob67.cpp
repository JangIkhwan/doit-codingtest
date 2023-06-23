/*
https://www.acmicpc.net/problem/11725

23-06-23 16:04 ~ 16:19
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[100001];
bool visited[100001];
int parents[100001];

void dfs(int cur, int parent) {
	visited[cur] = true;
	parents[cur] = parent;
	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (!visited[next]) {
			dfs(next, cur);
		}
	}
}

int main(void) {
	int a, b;
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, -1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parents[i]);
	}
	return 0;
}