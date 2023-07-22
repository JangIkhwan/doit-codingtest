/*
https://www.acmicpc.net/problem/1654

23-07-22 20:08 ~ 20:51

랜선의 길이가 동일, 최대의 랜선의 길이 구하기 -> 이분탐색
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int getLineNum(vector<int>& lines, int length) {
	int num = 0;
	for (int line : lines) {
		num += line / length;
	}
	return num;
}

int findMaxLength(vector<int>& lines, int N, int longest) {
	unsigned int lo = 1;
	unsigned int hi = longest + 1;
	while (lo + 1 < hi) {
		unsigned int mid = (lo + hi) / 2;
		if (getLineNum(lines, mid) >= N) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}

int main(void) {
	int K, N;
	int line;
	vector<int> lines;
	scanf("%d %d", &K, &N);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &line);
		lines.push_back(line);
	}
	int longest = -1;
	for (int line : lines) {
		if (line > longest) {
			longest = line;
		}
	}
	printf("%d\n", findMaxLength(lines, N, longest));
	return 0;
}
