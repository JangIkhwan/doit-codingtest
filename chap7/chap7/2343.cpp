/*
* https://www.acmicpc.net/problem/2343
* 23-05-22 22:24 
* 
* 22-05-23 11:53분 종료 55분 소요
* 
* 이분탐색을 사용하는 것은 좋은데 시간 복잡도 분석이 너무 어려움.
* 
* 
*/
#include <iostream>
using namespace std;

int N, M;
int sum[100001];

double assignToBlueray(int start, int end, int size, int assigned) {
	if (assigned == M) {
		if (start == N + 1) { //
			return 0.0;
		}
		return double(sum[end] - sum[start - 1]);
	}
	int lo = start - 1;
	int hi = end + 1;
	int key = size;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2; //
		if (sum[mid] - sum[start - 1] <= key) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return assignToBlueray(lo + 1, end, size, assigned + 1);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int lecture;
		cin >> lecture;
		sum[i] = sum[i - 1] + lecture;
	}

	int totalSum = sum[N];
	int size = sum[N] / M;
	while (true) {
		double remain = assignToBlueray(1, N, size, 0);
		if (remain == 0.0) {
			break;
		}
		size += 1; //
	}
	cout << size << "\n";

	return 0;
}