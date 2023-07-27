/*
https://www.acmicpc.net/problem/11050

23-07-07 22:26 ~ 22:36

생각해볼 점
- 조합론의 관점에서 유도한 점화식을 이용해서 문제를 해결할 수 있음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	int N, K;
	int C[11][11];

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}
	printf("%d", C[N][K]);

	return 0;
}
