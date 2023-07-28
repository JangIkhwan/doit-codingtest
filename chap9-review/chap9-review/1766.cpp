/*
https://www.acmicpc.net/problem/1766

23-07-27 19:19 ~ 19:45

������ ���� ����, ����� ������ �����ؾ� �ϹǷ� ���������� ���
�׷��� ������ ���� �������� Ǯ���� ������ ��...

4 - 2, 3 - 1

�켱���� ť�� �̿�?

���� �Է�
3 - 5 - 2, 4 - 1

ť = 3 4
4
4 5
5
1 5
5
2

��� = 3 4 1 5 2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int inDegree[32001];
int result[32001];
vector<int> graph[32001];

void topologicalSort() {
	int k = 1;
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			pq.push(-i); // �켱���� ť�� ū ���� ���� ��ȯ�ϱ� ������ ����ȭ
		}
	}
	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();
		result[k++] = now;
		for (int next : graph[now]) {
			inDegree[next] -= 1;
			if (inDegree[next] == 0) {
				pq.push(-next);
			}
		}
	}
}

int main(void) {
	int A, B;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &A, &B);
		graph[A].push_back(B);
		inDegree[B] += 1;
	}
	topologicalSort();
	for (int i = 1; i <= N; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}
