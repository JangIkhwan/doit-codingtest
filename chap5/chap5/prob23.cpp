/*
* 23-05-17 19:49 ~ 20:03, https://www.acmicpc.net/problem/11724
* 
* ¼º°ø
*/
#include <iostream>
using namespace std;

bool edge[1001][1001];
bool visited[1001];
int N, M;

void dfs(int cur) {
	if (visited[cur]) {
		return;
	}
	visited[cur] = true;
	for (int next = 1; next <= N; next++) {
		if (!visited[next] && edge[cur][next]) { //
			dfs(next);
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edge[v1][v2] = edge[v2][v1] = true;
	}

	int compNum = 0;
	for (int start = 1; start <= N; start++) {
		if (!visited[start]) {
			dfs(start);
			compNum++;
		}
	}
	cout << compNum << "\n";

	return 0;
}
