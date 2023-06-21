/*
https://www.acmicpc.net/problem/11403

23-06-20  21:10 ~ 21:26
1차 : 성공

다시 풀어보기...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
using namespace std;

int INF = 1000000;

int N;
int A[101][101];

void floydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (A[i][k] + A[k][j] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
}

int main(void) {
	int num;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			if (num == 0) {
				A[i][j] = INF;
			}
			else if (num == 1) {
				A[i][j] = 1;
			}
		}
	}

	floydWarshall();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == INF || A[i][j] == 0) {
				printf("0 ");
			}
			else {
				printf("1 ");
			}
		}
		printf("\n");
	}

	return 0;
}