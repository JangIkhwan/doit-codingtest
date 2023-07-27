/*
https://www.acmicpc.net/problem/11051

23-07-26 14:06
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int C[1001][1001];

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 0 || i == j) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = ((C[i - 1][j - 1] % 10007) + (C[i - 1][j] % 10007)) % 10007; // 수식 작성에 주의하자
			}
		}
	}
	printf("%d\n", C[N][K]);

	return 0;
}