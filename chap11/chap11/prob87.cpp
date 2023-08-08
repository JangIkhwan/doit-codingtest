/*
https://www.acmicpc.net/problem/10844

23-08-08 22:38 ~ 23:21

1차시도 성공

결과값의 오버플로우 주의

완전탐색으로 풀면 10^n에 비례
차이가 1인 수를 차례로 선택해나가는 것으로 개선하더라도 2^n에 비례

더 빠른 방법은?
관찰해보니 계단수의 일부분도 계단수임
맨 앞자리수가  a이고 길이가 n인 계단수를 구하는 함수를 
f(n, a)라고 하자.
f(n, a) = f(n - 1, 0) + f(n - 1, a - 1) + f(n - 1, a + 1); 이라고 잘못생각함.
진짜 점화식은 f(n, a) = f(n - 1, a - 1) + f(n - 1, a + 1) 임

생각해볼점
- 항상 다차원배열로 메모이제이션을 할 수 있을까? 
공간복잡도를 개선하기 위해서 점화식을 개선해야할 때가 생길까?
- 시간복잡도는 얼마일까? 부분문제 수는 1000개 정도이니 빠를 것 같긴 한데.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int memo[101][10];

int countStairNumber(int length, int first) {
	if (first < 0 || first > 9) return 0;
	if (length == 1) return 1;  //
	int& ret = memo[length][first];
	if (ret != -1) return ret;
	ret = countStairNumber(length - 1, first + 1) % 1000000000;
	//cout << "count(" << length - 1 << ", " << first + 1 << ") = " << ret << endl;
	int temp = countStairNumber(length - 1, first - 1) % 1000000000;
	//cout << "count(" << length - 1 << ", " << first - 1 << ") = " << ret << endl;
	ret += temp;
	return ret % 1000000000;
}

int main(void) {
	int N, result;
	memset(memo, -1, sizeof(memo));
	scanf("%d", &N);
	result = 0;
	for (int first = 1; first <= 9; first++) {
		result += countStairNumber(N, first);
		result %= 1000000000; // 누적합을 구할 때 오버플로우에 발생 가능
	}
	printf("%d", result);
	return 0;
}