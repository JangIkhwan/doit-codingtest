/*
https://www.acmicpc.net/problem/1516

23-06-09 14:07 ~ 14:47

1차 시도 : 주어진 시간을 넘어섬
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> graph[501];
int inDegree[501];
int buildTime[501];
int result[501];

void calcTotalBuildTime() {
	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			qu.push(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		int front = qu.front();
		qu.pop();
		result[front] += buildTime[front];
		for (int next : graph[front]) {
			result[next] += buildTime[front];
			if (--inDegree[next] == 0) {
				qu.push(next);
			}
		}
	}
}

int main(void) {
	int prev;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> buildTime[i];
		while (true) {
			cin >> prev;
			if (prev == -1) {
				break;
			}
			graph[prev].push_back(i);
		}
	}

	calcTotalBuildTime();

	for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}
}

