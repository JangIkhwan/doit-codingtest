/*
https://www.acmicpc.net/problem/2252
23-06-08 15:55 ~ 18:18

생각해볼 부분
- 학생들을 노드, 비교를 엣지라고 생각했을 때 노드의 순서를 구하는 문제가 됨
- 답이 여러 개일 때 아무거나 출력해도 상관이 없다는 점에서 위상정렬의 특징을 떠올려야 함.

기억하기
- 위상정렬은 '사이클이 없는 방향 그래프'에서 노드의 순서를 구할 때 사용함.
- '순서가 있는 작업'들을 순서대로 나열할 때 사용함
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
		// 사이클이 존재함. 위상정렬이 불가능한 경우를 알아낼 수 있음.
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
