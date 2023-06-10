/*
* 23-06-06 16:17
*/
#include <iostream>
using namespace std;

int N;
int set[1000001];

void initSet() {
	for (int i = 0; i < N; i++) {
		set[i] = i;
	}
}

int findSet(int i) {
	if (set[i] == i) {
		return set[i];
	}
	return set[i] = findSet(set[i]);
}

void unionSet(int i, int j) {
	int root1 = findSet(i);
	int root2 = findSet(j);
	if (root1 < root2) {
		set[root2] = root1;
	}
	else {
		set[root1] = root2;
	}
}

int main(void) {
	int M;
	cin >> N >> M;

	initSet();
	for (int i = 1; i <= M; i++) {
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0) {
			unionSet(a, b);
		}
		else if (oper == 1) {
			int root1 = findSet(a);
			int root2 = findSet(b);
			if (root1 == root2) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}