/*
세그먼트 트리
- 데이터가 계속 변하는 상황에서 많은 쿼리를 처리해야할 때 사용할 수 있음
- 대표적으로 구간합, 최댓값, 최솟값을 구할 때 사용할 수 있음
- 구간합을 선형적 방법으로 구하면 구간의 길이 N에 비례하는 시간이 걸림
만약 구간합의 원소가 M번 바뀌면 구간합을 구하는데 MN에 비례하는 시간이
걸리게 되어서 M과 N이 큰 경우에는 너무 느려진다는 문제가 있음
- 세그먼트 트리를 이용하면 쿼리를 구하는데 log N에 비례하는 시간이 걸림
- 세그먼트 트리의 리프노드 수는 N개여야 하는데, 이때 트리는 
N > 2^k를 만족하는 최대의 k에 2를 곱한 만큼의 노드가 필요함
실전에서는 원소의 개수에 4를 곱하면 될 것으로 보임
*/
#include <iostream>
using namespace std;

const int NUMBER = 12;

int A[NUMBER] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
int tree[NUMBER * 4]; // 보통 최대 개수의 4배만큼 설정하면 됨

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = A[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) { // 주의
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, int diff) {
	if (index < start || index > end) {
		return;
	}
	tree[node] += diff;
	int mid = (start + end) / 2;
	if (start != end) {
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main(void) {
	init(1, 0, NUMBER - 1);
	
	cout << "0 ~ 11까지의 합 : " << sum(1, 0, NUMBER - 1, 0, NUMBER - 1) << "\n";

	cout << "5 ~ 7까지의 합 : " << sum(1, 0, NUMBER - 1, 5, 7) << "\n";

	update(1, 0, NUMBER - 1, 4, -3);
	
	cout << "0 ~ 11까지의 합 : " << sum(1, 0, NUMBER - 1, 0, NUMBER - 1) << "\n";

	return 0;
}