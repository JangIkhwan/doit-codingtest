/*
https://www.acmicpc.net/problem/2193

23-08-05 

15:36 ~ 48
1차 시도: 실패

p(length, recent) = p(length - 1, 1) + p(length - 1, 0) ? 

20:40 ~ 21:09
2차 시도 : 성공

생각해보니 1 다음에 올 수 있는 것은 0 또는 01

문제점
90을 입력하니 음수가 나옴. 자료형이 int 여서 문제임
-> long long으로 변경하자

생각해볼 점
- 동적계획법에서 점화식은 다양한 방식으로 구할 수 있으니
다른 점화식을 생각해보자. 원래 시도는 왜 실패했을까?
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int N;
int cnt;
long long memo[91]; //

long long numOfPinaryNumber(int length) { //
	if (length < 0) {
		return 0;
	}
	if (length == 0) {
		return 1;
	}
	long long& ret = memo[length];
	if (ret != -1) {
		return ret;
	}
	return ret = numOfPinaryNumber(length - 1) + numOfPinaryNumber(length - 2);
}

int main(void) {
	scanf("%d", &N);
	memset(memo, -1, sizeof(memo));
	printf("%lld", numOfPinaryNumber(N - 1));
	return 0;
}

// 실패한 코드들

int numOfPinaryNumber1(int length, int recent) {
	if (length < 0) {
		return 0;
	}
	if (length == 0) {
		return 1;
	}
	/*int& ret = memo[length][recent];
	if (ret != -1) {
		return ret;
	}
	ret = numOfPinaryNumber1(length - 1, 0);
	if (recent == 1) {
		ret += numOfPinaryNumber1(length - 2, 1);
	}
	else {
		ret += numOfPinaryNumber1(length - 1, 1);
	}
	return ret;*/
}

int numOfPinaryNumber0(int length, int recent) {
	if (length < 0) {
		return 0;
	}
	if (length == 0) {
		return 1;
	}
	/*int& ret = memo[length][recent];
	if (ret != -1) {
		return ret;
	}
	ret = numOfPinaryNumber0(length - 1, 0);
	if (recent != 1){
		ret += numOfPinaryNumber0(length - 2, 1);
	}
	return ret;*/
}