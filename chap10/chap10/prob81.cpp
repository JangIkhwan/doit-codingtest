/*
23-08-01 19:55 ~ 19:05, 20:07 ~ 20:40  ... ~ 21:30

순열에서 맨 앞의 값이 나머지 숫자에서 k 번째 수일때, 
(k - 1)(N-1)! 만큼 수를 더해야 함

반례
20
2 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

생각해볼 점
- 조합문제에서는 오버플로우에 주의해야함. 
- 순열을 구성할 때 선택되지 않은 수에서 수를 차례로 선택한다고 
생각하면 코드를 더 개선할 수 있을 것 같음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int seq[21];
long long P[21]; //
int ranking[21];
bool selected[21];

void printNumber() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (seq[i] > seq[j]) {
				ranking[i] += 1;
			}
		}
	}
	long long number = 1;//
	for(int now = 1; now <= N; now++) {
		number += ranking[now] * P[N - now];
	}
	printf("%lld\n", number);
}

void printSeq(long long k) {
	for (int now = 1; now <= N; now++) {
		int skip = k / P[N - now];
		int skipCount = 0;
		for (int toPick = 1; toPick <= N; toPick++) {
			if (selected[toPick]) continue;
			if (skip == skipCount) {
				seq[now] = toPick;
				selected[toPick] = true;
				break;
			}
			skipCount += 1;
		}
		k -= skip * P[N - now];
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", seq[i]);
	}
	printf("\n");
}

int main(void) {
	int prob;
	long long k;
	scanf("%d", &N);
	scanf("%d", &prob);
	P[0] = 1;
	for (int i = 1; i <= N; i++) {
		P[i] = i * P[i - 1];
		//printf("%lld\n", P[i]);
	}
	if (prob == 1) {
		scanf("%lld", &k); //
		printSeq(k - 1);
	}
	else if (prob == 2) {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &seq[i]);
		}
		printNumber();
	}
	return 0;
}
