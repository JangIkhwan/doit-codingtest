/*
https://www.acmicpc.net/problem/11437

23-07-04 21:41 ~ 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50001;
const int LOG = 17; // 얼마로 지정해야하나?

int N, M;
vector<int> tree[MAX];
int parent[MAX][LOG];
int depth[MAX];

void dfs(int now, int prev, int level) {
	parent[now][0] = prev;
	depth[now] = level;
	for (int next : tree[now]) {
		if (next != prev) {
			dfs(next, now, level + 1);
		}
	}
}

void setParent(int root) {
	dfs(root, 0, 0);
	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			a = parent[a][i];
		}
	}
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main(void) {
	int a, b;
	int result[10001];
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	setParent(1);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		result[i] = LCA(a, b);
	}
	for (int i = 1; i <= M; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}