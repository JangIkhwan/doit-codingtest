/*
https://www.acmicpc.net/problem/20040
23-07-20 17:12 ~ 17:35

싸이클 형성 여부 판단 -> 유니온파인드?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX = 500000; // 문제에 주어진 범위를 잘 확인해야 함

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
			if (!detected) { // 처음으로 싸이클이 형성된 차례를 출력해야 함
				result = i;
				detected = true;
			}
		}
	}
	cout << result << "\n";
	return 0;
}
