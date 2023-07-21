#include <iostream>
using namespace std;

const int MAX = 11;

class UnionFind {
	int parent[MAX];
public:
	UnionFind() {
		for (int i = 1; i < MAX; i++) {
			parent[i] = i;
		}
	}
	int find(int i) {
		if (parent[i] == i) {
			return i;
		}
		return parent[i] = find(parent[i]); // ã�ƾ��ϴ� �θ� ������ �θ����� �� �����غ��ƾ� ��!
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

}