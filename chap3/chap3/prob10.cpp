/*
* 23-05-11, https://www.youtube.com/watch?v=0lA6QOTt2PQ&t=228s
*  50분만에 해결...
*/

#include <iostream>
#include <stack>
using namespace std;

int N;
int A[1000001];
int nge[1000001];

void printNGE() {
	stack<int> st;
	
	int i = N;
	while (i > 0) {
		int toInsert = A[i];
		if (!st.empty()){
			while (!st.empty() && st.top() <= toInsert) {
				st.pop();
			}
			if (!st.empty() && st.top() > toInsert) {
				nge[i] = st.top();
			}
		}
		if (st.empty()) {
			nge[i] = -1;
		}
		st.push(toInsert);
		i -= 1;
	}

	for (int i = 1; i <= N; i++) {
		cout << nge[i] << " ";
	}
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	printNGE();

	return 0;
}