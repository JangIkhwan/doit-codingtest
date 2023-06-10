#include <iostream>
using namespace std;

void selectionSort(int A[], int size) {
	for (int i = 0; i < size; i++) {
		int largest = i;
		for (int j = i; j < size; j++) {
			if (A[j] > A[largest]) {
				largest = j;
			}
		}
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
	}
}

int main(void) {
	int N;
	cin >> N;
	
	int digit[10];
	int digitNum = 0;
	while (N > 0) {
		digit[digitNum] = N % 10;
		digitNum += 1;
		N = N / 10;
	}

	selectionSort(digit, digitNum);

	for (int i = 0; i < digitNum; i++) {
		cout << digit[i];
	}
	cout << "\n";
}