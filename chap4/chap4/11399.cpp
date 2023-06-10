#include <iostream>
using namespace std;

void insertionSort(int A[], int size) {
	for (int i = 1; i <= size; i++) {
		int j = i;
		while (j > 1 && A[j] < A[j - 1]) {
			int temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
}

int main(void) {
	int N;
	int P[1001];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	insertionSort(P, N);

	int totalSum = 0;
	int enlapsedTime = 0;
	for (int i = 1; i <= N; i++) {
		enlapsedTime += P[i];
		totalSum += enlapsedTime;
	}

	cout << totalSum << "\n";

	return 0;
}