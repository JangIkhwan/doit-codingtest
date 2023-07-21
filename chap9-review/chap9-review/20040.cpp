/*
https://www.acmicpc.net/problem/20040
23-07-20 17:12 ~ 17:35

����Ŭ ���� ���� �Ǵ� -> ���Ͽ����ε�?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX = 500000; // ������ �־��� ������ �� Ȯ���ؾ� ��

class DisjointSet {
	int parent[MAX];
public:
	DisjointSet() {
		for (int i = 0; i < MAX; i++) {
			parent[i] = i;
		}
	}
	int find(int i) {
		if (parent[i] == i) {
			return i;
		}
		return parent[i] = find(parent[i]);
	}
	void merge(int i, int j) {
		int u = find(i);
		int v = find(j);
		if (u != v) {
			parent[u] = v;
		}
	}
};

int main(void) {
	int N, M;
	int a, b, result = 0;
	bool detected = false;
	DisjointSet set;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		if (set.find(a) != set.find(b)) {
			set.merge(a, b);
		}
		else {
			if (!detected) { // ó������ ����Ŭ�� ������ ���ʸ� ����ؾ� ��
				result = i;
				detected = true;
			}
		}
	}
	cout << result << "\n";
	return 0;
}
