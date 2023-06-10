/*
* 23-05-14
* 1차 시도 실패, 60분 소요...
*/

#include <iostream>
#include <stack>
using namespace std;

int A[500001];

int main(void) {
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	stack<int> st;
	int result = 1;
	for (int i = 1; i <= N; i++) {
		int cur = A[i];
		while (!st.empty() && st.top() > cur) {
			st.pop();
			result += 1;
		}
		st.push(cur);
	}
	cout << result << "\n";

	return 0;
}


int main1(void) {
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int result = 1;
	for (int i = 1; i < N; i++) {
		if (A[i] > A[i + 1]) {
			result += 1;
		}
	}
	cout << result;

	return 0;
}

int main0(void) {
	int N;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int lastReversed = 0;
	for (int i = 1; i < N; i++) {
		if (A[i] > A[i + 1]) {
			lastReversed = i;
		}
	}
	cout << lastReversed + 1 << "\n";

	return 0;
}

