/*
* https://www.acmicpc.net/problem/18352
* 
* 21-06-01 22:50 ~ 23:12
* - bfs 구현에서 거리를 구할 때 어려움이 있었음. 이 패턴을 잘 기억해야 할 듯...
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
vector<int> graph[300001];
bool visited[300001];
int distances[300001];

void bfs(int start) {
	queue<int> qu;
	qu.push(start);
	visited[start] = true;
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		for (int next : graph[cur]) {
			if (!visited[next]) {
				qu.push(next);
				visited[next] = true;
				distances[next] = distances[cur] + 1;
			}
		}
	}
}

int main(void) {
	cin >> N >> M >> K >> X;
	for (int i = 1; i <= M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}

	bfs(X);

	bool noCity = true;
	for (int i = 1; i <= N; i++) {
		if (distances[i] == K) {
			cout << i << "\n";
			noCity = false;
		}
	}
	if (noCity) {
		cout << "-1\n";
	}

	return 0;
}

