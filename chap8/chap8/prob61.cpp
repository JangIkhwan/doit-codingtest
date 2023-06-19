/*
23-06-19 17:44 ~ 18:11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
using namespace std;

int INF = 20000000; // INT_MAX는 안됨. 
int N, M;
int W[101][101];
int result[101][101];

void floydWarshall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j && W[i][j] == 0) {
				result[i][j] = INF;
			}
			else{
				result[i][j] = W[i][j];
			}
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (result[i][k] + result[k][j] < result[i][j]) { //  INF 값이 INF_MAX면 INF의 합이 음수가 되어서 안됨...
					result[i][j] = result[i][k] + result[k][j];
				}
			}
		}
	}
}

int main(void) {
	int a, b, c;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (W[a][b] == 0 || (W[a][b] != 0 && c < W[a][b])) {
			W[a][b] = c;
		}
	}

	floydWarshall(); //  함수호출을 잊지 말자...

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (result[i][j] == INF) {
				printf("0 ");
			}
			else {
				printf("%d ", result[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}