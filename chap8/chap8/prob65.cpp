/*
https://www.acmicpc.net/problem/1389

23-06-22 18:23 ~ 18:43
1차에 성공
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int INF = 1000000;

int N, M;
int dists[101][101];

int kevinBacon() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dists[i][k] + dists[k][j] < dists[i][j]) {
					dists[i][j] = dists[i][k] + dists[k][j];
				}
			}
		}
	}
	int number = INF;
	int picked = -1;
	for (int user = 1; user <= N; user++) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (dists[user][i] != INF) {
				sum += dists[user][i];
			}
		}
		if (sum < number) {
			number = sum;
			picked = user;
		}
	}
	return picked;
}

int main(void) {
	int a, b;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		dists[a][b] = dists[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (dists[i][j] == 0) {
				dists[i][j] = INF;
			}
		}
	}

	printf("%d\n", kevinBacon());

	return 0;
}
