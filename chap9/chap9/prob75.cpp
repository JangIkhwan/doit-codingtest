/*
https://www.acmicpc.net/problem/11438

23-07-07 21:37 ~ 22:02

����� ��
- Ʈ���� ���̸� �ʰ����� �ʴ� 2^K�� �ִ��� K�� parent�� ���� ���� ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
const int LOG = 18; // LOG ���� �������� ���� �� ����

int N, M;
vector<int> tree[MAX]; // ��������Ʈ ������� Ʈ���� �����ϴ� ��Ŀ��� �Ǽ����� ����
int depth[MAX];
int parent[MAX][LOG];
int result[100001];

void dfs(int now, int prev) {
	parent[now][0] = prev;
	depth[now] = depth[prev] + 1;
	for (int next : tree[now]) {
		if (next != prev) {
			dfs(next, now);
		}
	}
}

void setParent() {
	dfs(1, 0);
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
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	setParent(); // �Լ�ȣ���� ������ �ʵ��� �Ű澲��
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
