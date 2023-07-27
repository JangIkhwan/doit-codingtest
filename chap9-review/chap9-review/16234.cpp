/*
https://www.acmicpc.net/problem/16234

23-07-26 16:15 ~ 

연합을 형성한후 업데이트할 때 시간복잡도가 N * N * N * N이 될 수 있음.
그래서 업데이트를 더 개선해야 함
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, L, R;
int A[51][51];
int unionNum[51][51];

int unionSum[2501];
int unionSize[2501];
int unionAvg[2501];

bool visited[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int y, int x, int num) {
	queue<pair<int, int>> qu;
	qu.push({ y, x });
	visited[y][x] = true;
	while (!qu.empty()) {
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();
		unionSum[num] += A[y][x];
		unionSize[num] += 1;
		unionNum[y][x] = num;
		for (int direct = 0; direct < 4; direct++) {
			int nextY = y + dy[direct];
			int nextX = x + dx[direct];
			if (nextX < 1 || nextX > N || nextY < 1 || nextY > N) continue;
			int diff = abs(A[nextY][nextX] - A[y][x]);
			if (!visited[nextY][nextX] && diff >= L && diff <= R) {
				qu.push({ nextY, nextX });
				visited[nextY][nextX] = true;
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d", &N, &L, &R);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	int unionCount;
	int dayCount = 0;
	while (true) {
		memset(unionSum, 0, sizeof(unionSum));
		memset(unionSize, 0, sizeof(unionSize));
		memset(visited, 0, sizeof(visited));
		unionCount = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if(!visited[y][x])
					bfs(y, x, unionCount++);
			}
		}
		if (unionCount == N * N) break;
		for (int i = 0; i < unionCount; i++) {
			unionAvg[i] = unionSum[i] / unionSize[i];
		}
		memset(visited, 0, sizeof(visited));
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				A[y][x] = unionAvg[unionNum[y][x]];
			}
		}
		dayCount += 1;
	}
	printf("%d", dayCount);
	return 0;
}

void dfs(int y, int x) {
	visited[y][x] = true;
	A[y][x] = unionAvg[unionNum[y][x]];
	for (int direct = 0; direct < 4; direct++) {
		int nextY = y + dy[direct];
		int nextX = x + dx[direct];
		if (nextX < 1 || nextX > N || nextY < 1 || nextY > N) continue;
		if (!visited[nextY][nextX]) {
			dfs(nextY, nextX);
		}
	}
}