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
	int popedLow = 1234567;
	int changedNum = 0;
	for (int i = 1; i <= N; i++) {
		int cur = A[i];
		while (!st.empty() && st.top() > cur) {
			int poped = st.top();
			popedLow = (poped < popedLow) ? poped : popedLow;
			st.pop();
			changedNum++;
		}
		if (cur <= popedLow) {
			st.push(cur);
		}
		else {
			changedNum++;
		}
	}

	cout << changedNum + 1 << "\n";

	return 0;
}