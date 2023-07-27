/*
23-07-24 21:11 ~ 

- 2차원 배열에서 dfs로 연합들을 구한 후에 인구 이동시킴
- dfs로 다음에 방문할 노드는 인구 차이가 L ~ R 사이임
- 모든 칸에 대해서 bfs를 수행했다면 종료하고 총 몇 일인지 출력

참고
https://www.acmicpc.net/board/view/86503
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

int N, L, R;
int A[51][51];
int number[51][51];
int unionSum[2500];
int unionSize[2500];

bool visited[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool bfs(int y, int x, int num) {
	queue<pair<int, int>> qu;
	qu.push({ y, x });
	visited[y][x] = true;
	while (!qu.empty()) {
		y = qu.front().first;
		x = qu.front().second;
		qu.pop();
		number[y][x] = num;
		unionSum[num] += A[y][x];
		unionSize[num] += 1;
		for (int direct = 0; direct < 4; direct++) {
			int newX = x + dx[direct];
			int newY = y + dy[direct];
			if (newX < 1 || newX > N || newY < 1 || newY > N) continue;
			int diff = abs(A[newY][newX] - A[y][x]);
			if (!visited[newY][newX] && diff >= L && diff <= R) { //]
				qu.push({ newY, newX }); //
				visited[newY][newX] = true;
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
	bool unionFormed;
	while (true) {
		unionCount = 0; 
		memset(visited, 0, sizeof(visited));
		memset(unionSum, 0, sizeof(unionSum));
		memset(unionSize, 0, sizeof(unionSize));
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (!visited[y][x])
					bfs(y, x, unionCount++);
			}
		}
		if (!unionFormed) break;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				for (int num = 0; num < unionCount; num++) {
					if (number[y][x] == num) {
						A[y][x] = unionSum[num] / unionSize[num];
					}
					
				}
			}
		}
		dayCount += 1;
	}
	printf("%d\n", dayCount);
	return 0;
}

int unionAvg[2500];

void dfs(int y, int x, int num) {
	visited[y][x] = true;
	number[y][x] = num;
	unionSum[num] += A[y][x];
	unionSize[num] += 1;
	for (int direct = 0; direct < 4; direct++) {
		int newX = x + dx[direct];
		int newY = y + dy[direct];
		if (newX < 1 || newX > N || newY < 1 || newY > N) continue;
		int diff = abs(A[newY][newX] - A[y][x]);
		if (!visited[newY][newX] && diff >= L && diff <= R) { //
			dfs(newY, newX, num); //
		}
	}
}

int main0(void) {
	scanf("%d %d %d", &N, &L, &R);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	int unionCount;
	int dayCount = 0;
	while (true) {
		unionCount = 0;
		memset(visited, 0, sizeof(visited));
		memset(unionSum, 0, sizeof(unionSum));
		memset(unionSize, 0, sizeof(unionSize));
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (!visited[y][x])
					dfs(y, x, unionCount++);
			}
		}
		if (unionCount == N * N) break;
		for (int num = 0; num < unionCount; num++) {
			unionAvg[num] = unionSum[num] / unionSize[num];
		}
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				for (int num = 0; num < unionCount; num++) {
					if (number[y][x] == num) {
						A[y][x] = unionAvg[num];
					}
				}
			}
		}
		dayCount += 1;
	}
	printf("%d\n", dayCount);
	return 0;
}
