/*
23-05-08, https://www.acmicpc.net/problem/1253
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int A[2001];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	sort(A + 1, A + N + 1);
	
	int goodNumCount = 0;
	for (int cur = 1; cur <= N; cur++) {
		int start = 1; // 
		int end = N;  //  
		int currentNum = A[cur];
		while (start < end) {  // 
			if (start == cur) { // start와 end를 변경했으니 이것이 종료조건을 만족하는지 다시 확인해야 함!
				start++;
			}
			if (end == cur) {
				end--;
			}
			if (start >= end) { //
				break;
			}
			int sum = A[start] + A[end];
			if (sum > currentNum) {
				end--;
			}
			else if (sum < currentNum) {
				start++;
			}
			else {
				goodNumCount++;
				break;
			}
		}
	}

	cout << goodNumCount << "\n";

	return 0;
}

int main0(void) {
	int N;
	cin >> N;

	int A[2001];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	sort(A + 1, A + N + 1);

	int goodNumCount = 0;
	for (int cur = 3; cur <= N; cur++) {
		int start = 1; //
		int end = cur - 1;
		int currentNum = A[cur];
		while (start <= end) { //
			int sum = A[start] + A[end];
			if (sum > currentNum) {
				end--;
			}
			else if (sum < currentNum) {
				start++;
			}
			else {
				goodNumCount++;
				break;
			}
		}
	}

	cout << goodNumCount << "\n";

	return 0;
}