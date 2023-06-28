/*
https://www.acmicpc.net/problem/1068

23-06-28 22:25 ~ 23:15 
½ÇÆÐ

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parents[50];
int children[50];
vector<int> tree[50];
bool visited[50];

void bfs(int start) {
	queue<int> qu;
	qu.push(start);
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		visited[now] = true;
		for (int next : tree[now]) {
			--children[next];
			if (next == parents[now]) continue;
			if (!visited[next]) {
				qu.push(next);
			}
		}
	}
}

int main(void) {
	int N, parent, exclude;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &parent);
		if (parent == -1) {
			continue;
		}
		parents[i] = parent;
		children[parent]++;
		tree[parent].push_back(i);
		tree[i].push_back(parent);
	}
	scanf("%d", &exclude);

	children[exclude] = -1;
	bfs(exclude);
	int leafCount = 0;
	for (int i = 0; i < N; i++) {
		if (children[i] == 0) {
			leafCount += 1;
		}
	}
	printf("%d", leafCount);

	return 0;
}

// int inDegree[50];
//void dfs(int cur) {
//	visited[cur] = true;
//	for (int next : tree[cur]) {
//		if (next == -1) continue;
//		if (!visited[cur]) {
//			dfs(next);
//		}
//	}
//	if (tree[cur].size() == 0) {
//		leafcount += 1;
//	}
//}
//
//int main(void) {
//	int n, root, exclude;
//	int parents[50];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d ", &parents[i]);
//		if (parents[i] == -1) {
//			root = i;
//			continue;
//		}
//		tree[parents[i]].push_back(i);
//	}
//	scanf("%d", &exclude);
//	
//	for (int i = 0; i < tree[parents[exclude]].size(); i++) {
//		if (tree[parents[exclude]][i] == exclude) {
//			tree[parents[exclude]][i] = -1;
//		}
//	}
//
//	dfs(root);
//
//	printf("%d", leafcount);
//
//	return 0;
//}