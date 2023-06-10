/*
* 23-05-16, 11:08
* 
* 1�� �õ� ����. 29�� �ҿ�. 
* 
*
* ���� �Ŀ� k��° ���� ���?
* 
* 2�� �õ� ����. 20�� �ҿ�.
* 
* 3�� �õ� ����.
* - �ð� �ʰ��� �߻��ϴ� ���� �� �ϳ��� ����� �����̾���. scanf�� printf�� ����ϴ� ���� �� ���� ��...
* - ���� �������� �־��� �ð� ���⵵�� N^2�̹Ƿ� �� ���������� ������� �ʴ� ���� ����! 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int A[5000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	sort(A + 1, A + N + 1);

	cout << A[K] << "\n";

	return 0;
}


void findKthNum(int A[], int start, int end, int K) {
	int pivot = A[start];
	int lo = start + 1;
	int hi = end;
	while (lo < hi) {
		while (lo <= end && A[lo] < pivot) {
			lo++;
		}
		while (hi >= start && A[hi] > pivot) {
			hi--;
		}
		if (lo < hi) {
			int temp = A[lo];
			A[lo] = A[hi];
			A[hi] = temp;
		}
	}
	A[start] = A[hi];
	A[hi] = pivot;
	if (hi == K) {
		return;
	}

	if (hi > K) {
		findKthNum(A, start, hi - 1, K);
	}
	else {
		findKthNum(A, hi + 1, end, K);
	}
}

int main1(void) {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	findKthNum(A, 1, N, K);

	cout << A[K] << "\n";

	return 0;
}


void quickSort(int A[], int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = A[start];
	int lo = start + 1;
	int hi = end;
	while (lo < hi) {
		while (lo <= end && A[lo] < pivot) {
			lo++;
		}
		while (hi >= start && A[hi] > pivot) {
			hi--;
		}
		if (lo < hi) {
			int temp = A[lo];
			A[lo] = A[hi];
			A[hi] = temp;
		}
	}
	A[start] = A[hi];
	A[hi] = pivot;

	quickSort(A, start, hi - 1);
	quickSort(A, hi + 1, end);
}


int main0(void) {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	quickSort(A, 1, N);

	cout << A[K] << "\n";

	return 0;
}

