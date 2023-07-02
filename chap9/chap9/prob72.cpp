/*
23-07-02 18:19~ 18:50
- 1차 시도 : 성공

생각해볼 점
- 세그먼트 트리 이론 복습 필요
- 세그먼트 트리 함수 이름을 segInit, segQuery, segUpdate로 정하는 것이 좋을 것 같음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NUM = 100000;
const int INF = 1000000001;
int A[MAX_NUM];
int tree[MAX_NUM * 4];
int result[1000001];

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = A[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
	}
}

int find(int node, int start, int end, int left, int right) {
	if (start > right || end < left) { // 조건식을 작성할 때 조금만 더 집중하자
		return INF;
	}
	else if (left <= start && end <= right) { // 조건식에서 변하는 값은 start와 end임
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
}

int main(void) {
	int N, M, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	init(1, 0, N - 1);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		result[i] = find(1, 0, N - 1, a - 1, b - 1); // 호출 시에 인덱스는 0부터!
	}
	
	for (int i = 1; i <= M; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}