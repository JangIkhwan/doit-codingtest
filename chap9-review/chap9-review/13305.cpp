/*
https://www.acmicpc.net/problem/13305

23-07-23 16:53 ~ 21, 18:42 ~ 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int dists[100000];
int cost[100001]; //

long long getMinCost(int start, int end){
	int dist = 0;
	int next;
	if (start >= end) return 0;
	for (next = start; next < end; next++) {
		if (cost[next] < cost[start]) {
			break;
		}
		dist += dists[next];
	}
	return (long long) (cost[start] * dist) + getMinCost(next, end);
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &dists[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &cost[i]);
	}
	printf("%lld", getMinCost(0, N - 1));
	return 0;
}

// 부분 정답
long long getMinCost0(int start, int end) {
	if (start == end) {
		return 0;
	}
	int wp;
	int dist = 0;
	for (wp = start; wp < end; wp++) { // 
		if (cost[wp] < cost[start]) {
			break;
		}
		dist += dists[wp];
	}
	return (long long)(cost[start] * dist) + getMinCost0(wp, end);
}

