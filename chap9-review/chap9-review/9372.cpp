/*
https://www.acmicpc.net/problem/9372
23-07-20 17:05

그래프가 주어질 때 N개의 정점을 최소의 엣지로 이어야 함 -> 트리
트리의 엣지의 수는 -> N - 1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T, N, M;
	int a, b;
	vector<int> result;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= M; i++) {
			scanf("%d %d", &a, &b);
		}
		result.push_back(N - 1);
	}
	for (int r : result) {
		printf("%d\n", r);
	}
	return 0;
}