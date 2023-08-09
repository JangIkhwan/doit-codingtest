/*
23-08-08 15:22 ~ 

맨 앞부터 숫자를 차례로 선택함
K를 이용해서 선택되지 않은 숫자 중 몇번째 수를 선택해야 하는지 알아내야 함.
i번째 수를 선택하고, K -= (i - 1) * P[remain]을 수행함.

주어진 수열의 맨 앞부터 차례로 판단함
만약 선택되지 않은 수에서 i번째 수라면 K += (i - 1) * P[remain]을 수행함.

기억할 점
- 입력 값의 범위를 꼭 확인하자
- 팩토리얼이나 조합을 사용할 때 오버플로우가 발생할 수 있으니 주의하자.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int seq[21];
bool picked[21];
long long P[21];

void printSequence(int N, long long K) {
	int toPick;
	for (int now = 0; now < N; now++) {
		int i = 0;
		while (K > i * P[N - now - 1]) {
			i++;
		}
		K -= (i - 1) * P[N - now - 1];
		int j = 0;
		for (toPick = 1; toPick <= N; toPick++) {
			if (!picked[toPick]) {
				if (i - 1 == j) {
					break;
				}
				j++;
			}
		}
		picked[toPick] = true;
		seq[now] = toPick;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", seq[i]);
	}
}

void printNumber(int N) {
	long long k = 0; //
	int i;
	for (int now = 0; now < N - 1; now++) {
		i = 0;
		for (int toPick = 1; toPick <= N; toPick++) {
			if (!picked[toPick]){
				if (seq[now] == toPick) {
					k += i * P[N - now - 1];
					picked[toPick] = true; // 
					break;
				}
				i++;
			}
		}
	}
	k += 1;
	printf("%lld", k);
};

int main(void) {
	int N;
	long long K;
	int prob;
	scanf("%d", &N);
	P[0] = 1;
	for (int i = 1; i <= N; i++) {
		P[i] = i * P[i - 1];
	}
	scanf("%d", &prob);
	if (prob == 1) {
		scanf("%lld", &K); //
		printSequence(N, K);
	}
	else if (prob == 2) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &seq[i]);
		}
		printNumber(N);
	}
	return 0;
}

