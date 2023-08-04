/*
23-08-04 20:23 ~ 20:53

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int workTime[16];
int profit[16];

int memo[16];

int maxProfit(int day, int N) {
	if (day > N) return 0;
	int& ret = memo[day];
	if (ret != -1) return ret;	
	ret = maxProfit(day + 1, N); 
	if (day + workTime[day] - 1 <= N) { // 퇴사일을 넘어서는지 판단하는 조건식에서 실수
		ret = max(ret , profit[day] + maxProfit(day + workTime[day], N));
	}
	return ret;
}

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &workTime[i], &profit[i]);
	}
	memset(memo, -1, sizeof(memo)); // 재귀를 이용한 동적계획법에서 memo 배열을 초기화해야 함에 주의
	printf("%d", maxProfit(1, N));
	return 0;
}
