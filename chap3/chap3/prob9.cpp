/*
* 23-05-11, https://www.acmicpc.net/problem/1874
* 42분만에 해결
*/

#include <iostream>
#include <stack>
using namespace std;

int N;
int A[100001];

void judgeSequence() {
	stack<int> st;
	char operOrder[200001];
	int toRemove = N;
	int insertIdx = N;
	int operIdx = 2 * N; //
	
	while (insertIdx > 0) {
		st.push(A[insertIdx]);
		operOrder[operIdx] = '-';
		operIdx -= 1;
		while (!st.empty() && st.top() == toRemove) { //
			st.pop();
			toRemove -= 1;
			operOrder[operIdx] = '+';
			operIdx -= 1;

		}
		insertIdx -= 1;
	}

	if (st.empty()) {
		for (int oper = 1; oper <= 2 * N; oper++) {
			cout << operOrder[oper] << "\n";
		}
	}
	else {
		cout << "NO\n";
	}
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	judgeSequence();

	return 0;
}