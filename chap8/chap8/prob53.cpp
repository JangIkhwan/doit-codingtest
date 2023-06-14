/*
https://www.acmicpc.net/problem/2252
23-06-08 15:55 ~ 18:18

�����غ� �κ�
- �л����� ���, �񱳸� ������� �������� �� ����� ������ ���ϴ� ������ ��
- ���� ���� ���� �� �ƹ��ų� ����ص� ����� ���ٴ� ������ ���������� Ư¡�� ���÷��� ��.

����ϱ�
- ���������� '����Ŭ�� ���� ���� �׷���'���� ����� ������ ���� �� �����.
- '������ �ִ� �۾�'���� ������� ������ �� �����
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[32001];
int inDegree[32001];
int result[32001];

void TopologySort() {
	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			qu.push(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		// ����Ŭ�� ������. ���������� �Ұ����� ��츦 �˾Ƴ� �� ����.
		/*if (qu.empty()) {
			return;
		}*/
		int front = qu.front();
		qu.pop();
		result[i] = front;
		for (int next : graph[front]) {
			if (--inDegree[next] == 0) {
				qu.push(next);
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b] += 1;
	}

	TopologySort();

	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	}
}
