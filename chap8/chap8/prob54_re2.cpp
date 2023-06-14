/*
23-06-10 21:50
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int buildTime[501];
int totalTime[501];
vector<int> graph[501];
int inDegree[501];

void calcTotalTime() {
	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			qu.push(i);
		}
		totalTime[i] = buildTime[i];
	}
	for (int i = 1; i <= N; i++) {
		int front = qu.front();
		qu.pop();
		for (int node : graph[front]) {
			totalTime[node] = max(totalTime[node], totalTime[front] + buildTime[node]); 
			if (--inDegree[node] == 0) {
				qu.push(node);
			}
		}
	}
}

int main(void) {
	int required;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> buildTime[i];
		while (true) {
			cin >> required;
			if (required == -1) {
				break;
			}
			graph[required].push_back(i); // ����׷����� �� �ε����� ����
			inDegree[i] += 1; // ���߸��� �ʵ��� ����
		}
	}

	calcTotalTime();

	for (int i = 1; i <= N; i++) {
		cout << totalTime[i] << "\n";
	}

	return 0;
}

