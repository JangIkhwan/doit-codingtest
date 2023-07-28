/*
https://www.acmicpc.net/problem/1010

23-07-27 12:10 ~ 12:23

M개 중에서 N개를 선택하는 경우의 수를 구하면 됨 =  m C n
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T, N, M;
	int C[30][30];
	vector<int> result;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				if (j == 0 || i == j) {
					C[i][j] = 1;
				}
				else {
					C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
				}
			}
		}
		result.push_back(C[M][N]);
	}
	for (int res : result) {
		printf("%d\n", res);
	}
	return 0;
}
