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
		return parent[i] = find(parent[i]); // 찾아야하는 부모가 누구의 부모인지 잘 생각해보아야 함!
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