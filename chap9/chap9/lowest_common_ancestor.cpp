#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
const int LOG = 11;

vector<int> a[MAX];
int parents[MAX][LOG];
int depth[MAX];

void dfs(int now, int parent, int level) {
	parents[now][0] = parent;
	depth[now] = level;
	for (int next : a[now]) {
		if (next != parent) {
			dfs(next, now, level + 1);
		}
	}
}

void setParent(int root, int n) {
	dfs(root, 0, 0);
	for (int i = 1; i < LOG; i++) {
		for (int j = 0; j < n; j++) {
			parents[j][i] = parents[parents[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	for(int i = LOG - 1; i >= 0; i--){
		if (depth[a] - depth[b] >= (1 << i)) {
			a = parents[a][i];
		}
	}
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; i--) {
		if (parents[a][i] != parents[b][i]) {
			a = parents[a][i];
			b = parents[b][i];
		}
	}
	return parents[a][0];
}

int main(void) {
	int n = 21;
	// 0과 1을 연결합니다.
	a[0].push_back(1);
	a[1].push_back(0);
	// 0과 2를 연결합니다.
	a[0].push_back(2);
	a[2].push_back(0);
	// 1과 3을 연결합니다.
	a[1].push_back(3);
	a[3].push_back(1);
	// 1과 4를 연결합니다.
	a[1].push_back(4);
	a[4].push_back(1);
	// 2와 5을 연결합니다.
	a[2].push_back(5);
	a[5].push_back(2);
	// 2와 6을 연결합니다.
	a[2].push_back(6);
	a[6].push_back(2);
	// 3과 7을 연결합니다.
	a[3].push_back(7);
	a[7].push_back(3);
	// 3과 8을 연결합니다.
	a[3].push_back(8);
	a[8].push_back(3);
	// 4와 9를 연결합니다.
	a[4].push_back(9);
	a[9].push_back(4);
	// 4와 10을 연결합니다.
	a[4].push_back(10);
	a[10].push_back(4);
	// 4와 11을 연결합니다.
	a[4].push_back(11);
	a[11].push_back(4);
	// 8과 12를 연결합니다.
	a[8].push_back(12);
	a[12].push_back(8);
	// 8과 13을 연결합니다.
	a[8].push_back(13);
	a[13].push_back(8);
	// 9와 14를 연결합니다.
	a[9].push_back(14);
	a[14].push_back(9);
	// 10과 15를 연결합니다.
	a[10].push_back(15);
	a[15].push_back(10);
	// 13과 16을 연결합니다.
	a[13].push_back(16);
	a[16].push_back(13);
	// 13과 17을 연결합니다.
	a[13].push_back(17);
	a[17].push_back(13);
	// 14와 18을 연결합니다.
	a[14].push_back(18);
	a[18].push_back(14);
	// 15와 19를 연결합니다.
	a[15].push_back(19);
	a[19].push_back(15);
	// 17과 20을 연결합니다.
	a[17].push_back(20);
	a[20].push_back(17);

	setParent(0, n);
	cout << "5와 7의 LCA: " << LCA(5, 7) << '\n';
	cout << "15와 20의 LCA: " << LCA(15, 20) << '\n';
	cout << "16과 17의 LCA: " << LCA(16, 17) << '\n';
	cout << "10과 9의 LCA: " << LCA(10, 9) << '\n';
	cout << "3과 17의 LCA: " << LCA(3, 17) << '\n';
	return 0;
}

int parents0[MAX];

void dfs0(int now, int parent, int level) {
	parents0[now] = parent;
	depth[now] = level;
	for (int next : a[now]) {
		if (next != parent) {
			dfs0(next, now, level + 1);
		}
	}
}

int LCA0(int a, int b) {
	if (depth[a] > depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}

	while (depth[a] != depth[b]) {
		b = parents0[b];
	}
	while (a != b) {
		a = parents0[a];
		b = parents0[b];
	}
	return a;
}