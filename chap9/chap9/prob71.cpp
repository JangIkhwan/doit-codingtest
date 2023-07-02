/*
문제 : https://www.acmicpc.net/problem/2042

23-06-28 16:07 ~ 16:43
- 1차 시도 : 맞음

생각해볼 점
- 이 문제에서 자료형에 주의해서 코딩하는 것의 중요성을 깨달음
- 입력 데이터의 크기를 고려해서 변수의 자료형을 설정해야 함!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

long long init(vector<long long>& tree, vector<long long>& A, int node, int start, int end) {
	if (start == end) {
		return tree[node] = A[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = init(tree, A, node * 2, start, mid) + init(tree, A, node * 2 + 1, mid + 1, end);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	if (start >= left && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) {
		return;
	}
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main(void) {
	int N, M, K;
	scanf("%d %d %d\n", &N, &M, &K);
	vector<long long> A;
	vector<long long> tree(N * 4);
	vector<long long> result;
	long long temp; // 
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &temp); //
		A.push_back(temp);
	}
	init(tree, A, 1, 0, N - 1);
	long long a, b, c;
	for (int i = 1; i <= M + K; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			long long diff = c - A[b - 1];
			A[b - 1] = c;
			update(tree, 1, 0, N - 1, b - 1, diff);
		}
		else if (a == 2) {
			result.push_back(sum(tree, 1, 0, N - 1, b - 1, c - 1));
		}
	}
	for (int i = 0; i < K; i++) {
		printf("%lld\n", result[i]);
	}
	return 0;
}