/*
https://www.acmicpc.net/problem/1256

23-08-08 20:27 ~ 21:37 

aazz 1
azaz 2
azza 3
zaaz 4
zaza 5
zzaa 6

남은 a의 수가 a라고 가정
K가 C[i - 1][z]보다 크면 i번째 문자는 z, 그렇지 않으면 a.


aaazz 1
aazaz 2
aazza 3
azaaz 4
azaza 5

기억할 점
- 입력값의 범위를 잘 확인해서 조합을 어디까지 계산해야하는지 생각해보자
- 조합에서는 오버플로우가 발생할 수 있음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000000; //
long long C[201][101];

void printString(int N, int M, int K) {
	char result[201];
	int total = N + M;
	int aCount = 0;
	int zCount = 0;
	for (int i = 0; i <= total; i++) {
		for(int j = 0; j <= min(i, M); j++) {
			if (i == j || j == 0) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
				if (C[i][j] > MAX || C[i][j] < 0) C[i][j] = MAX + 1; // 오버플로우 방지 위해 추가
			}
		}
	}
	/*for (int i = 0; i <= total; i++) {
		for (int j = 0; j <= min(i, M); j++) {
			printf("%lld ", C[i][j]);
		}
		printf("\n");
	}*/
	
	if (K > C[total][M]) { // 오버플로우를 방지하지 않으면 -1이 출력이 안됨.
		printf("-1\n");
		return;
	}
	for (int now = 0; now < total; now++) {
		if (K > C[total - now - 1][M - zCount]) {
			result[now] = 'z';
			K -= C[total - now - 1][M - zCount];
			zCount += 1; // 
		}
		else {
			if (aCount < N) {
				result[now] = 'a';
				aCount += 1;
				continue;
			}
			if(zCount < M){
				result[now] = 'z';
				zCount += 1;
			}
		}
	}
	result[total] = '\0';
	printf("%s\n", result);
}

int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	
	printString(N, M, K);
	return 0;
}

