/*
23-08-02 18:12 ~ 18:47

힌트로 보아하니 그리디로 풀면 안됨...

점화식 도출 시도
m_1 = 0
m_2 = 1
m_3 = 1
m_4 = 2
m_5 = 1 * 2 + 1 = 3
m_6 = min(1 + M_3, 1 + m_2, 1 + m_5) = 2

실수
- 입력 에제를 가지고 나의 풀이가 맞는지 검증하려하지 않음
- 주어진 조건을 코드로 바르게 옮기지 못함. 
배열의 범위에 주의하자

생각해볼 점
- INF값이 아니라 operCount[i -1]를 초깃값으로 하는 것이 나아보임
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100000000;
int operCount[1000001]; // 

int main(void) {
	int N;
	scanf("%d", &N);
	operCount[1] = 0;
	operCount[2] = 1;
	operCount[3] = 1;
	for (int i = 4; i <= N; i++) {
		int temp = INF; // 
		if (i % 3 == 0) {
			temp = min(temp, operCount[i / 3]);
		}
		if (i % 2 == 0) {
			temp = min(temp, operCount[i / 2]);
		}
		temp = min(temp, operCount[i - 1]);
		temp += 1;
		operCount[i] = temp;
	}
	printf("%d\n", operCount[N]);
	return 0;
}

// 그리디를 이용한 방법, 그러나 올바른 값을 내지 못함.
int main0(void) {
	int N;
	int operCount = 0;
	scanf("%d", &N);
	while (N != 1) {
		if (N % 3 == 0) {
			N = N / 3;
		}
		else if (N % 2 == 0) {
			N = N / 2;
		}
		else {
			N = N - 1;
		}
		operCount += 1;
	}
	printf("%d", operCount);
	return 0;
}
