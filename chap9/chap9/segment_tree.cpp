#include <iostream>
using namespace std;

const int NUMBER = 12;

int A[NUMBER] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
int tree[NUMBER * 4];

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