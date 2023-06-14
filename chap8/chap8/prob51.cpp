/*
23-06-07 13:34 ~ 14:19
1차 시도 : 틀렸음

~ 14:30 
반례 발견 
6 3
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1
1 1 1 1 1 0
5 4 2

YES여야 하는데 NO가 나옴.

그 이유는 merge 메소드를 잘못 작성했기 때문임.

해결되었음.
*/
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
	int set[201];
public:
	UnionFind() {
		for (int i = 0; i < 201; i++) {
			set[i] = i;
		}
	}
	int find(int i) {
		if (set[i] == i) {
			return i;
		}
		return set[i] = find(set[i]);
	}
	void merge(int i, int j) { // 여기가 문제였음
		int root = find(i);
		set[j] = root;
	}
};

bool visited[201];
vector<int> graph[201];

void dfs(int cur, class UnionFind& uf) {
	visited[cur] = true;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			uf.merge(cur, next);
			dfs(next, uf);
		}
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int connect;
			cin >> connect;
			if (connect) {
				graph[i].push_back(j);
			}
		}
	}

	int route[1001];
	for (int i = 1; i <= M; i++) {
		cin >> route[i];
	}

	class UnionFind uf;
	dfs(route[M], uf);

	bool check = true;
	int root = uf.find(route[M]);
	for (int i = 1; i < M; i++) {
		if (uf.find(route[i]) != root) {
			check = false;
		}
	}

	if (check) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}

class UnionFind0 {
private:
	int set[201];
public:
	UnionFind0() {
		for (int i = 0; i < 201; i++) {
			set[i] = i;
		}
	}
	int find(int i) {
		if (set[i] == i) {
			return i;
		}
		return set[i] = find(set[i]);
	}
	void merge(int i, int j) {
		int root1 = find(i);
		int root2 = find(j);
		if (root1 < root2) { // 잘못된 부분..
			set[j] = root1;
		}
		else {
			set[i] = root2;
		}
	}
};
