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
	// 0�� 1�� �����մϴ�.
	a[0].push_back(1);
	a[1].push_back(0);
	// 0�� 2�� �����մϴ�.
	a[0].push_back(2);
	a[2].push_back(0);
	// 1�� 3�� �����մϴ�.
	a[1].push_back(3);
	a[3].push_back(1);
	// 1�� 4�� �����մϴ�.
	a[1].push_back(4);
	a[4].push_back(1);
	// 2�� 5�� �����մϴ�.
	a[2].push_back(5);
	a[5].push_back(2);
	// 2�� 6�� �����մϴ�.
	a[2].push_back(6);
	a[6].push_back(2);
	// 3�� 7�� �����մϴ�.
	a[3].push_back(7);
	a[7].push_back(3);
	// 3�� 8�� �����մϴ�.
	a[3].push_back(8);
	a[8].push_back(3);
	// 4�� 9�� �����մϴ�.
	a[4].push_back(9);
	a[9].push_back(4);
	// 4�� 10�� �����մϴ�.
	a[4].push_back(10);
	a[10].push_back(4);
	// 4�� 11�� �����մϴ�.
	a[4].push_back(11);
	a[11].push_back(4);
	// 8�� 12�� �����մϴ�.
	a[8].push_back(12);
	a[12].push_back(8);
	// 8�� 13�� �����մϴ�.
	a[8].push_back(13);
	a[13].push_back(8);
	// 9�� 14�� �����մϴ�.
	a[9].push_back(14);
	a[14].push_back(9);
	// 10�� 15�� �����մϴ�.
	a[10].push_back(15);
	a[15].push_back(10);
	// 13�� 16�� �����մϴ�.
	a[13].push_back(16);
	a[16].push_back(13);
	// 13�� 17�� �����մϴ�.
	a[13].push_back(17);
	a[17].push_back(13);
	// 14�� 18�� �����մϴ�.
	a[14].push_back(18);
	a[18].push_back(14);
	// 15�� 19�� �����մϴ�.
	a[15].push_back(19);
	a[19].push_back(15);
	// 17�� 20�� �����մϴ�.
	a[17].push_back(20);
	a[20].push_back(17);

	setParent(0, n);
	cout << "5�� 7�� LCA: " << LCA(5, 7) << '\n';
	cout << "15�� 20�� LCA: " << LCA(15, 20) << '\n';
	cout << "16�� 17�� LCA: " << LCA(16, 17) << '\n';
	cout << "10�� 9�� LCA: " << LCA(10, 9) << '\n';
	cout << "3�� 17�� LCA: " << LCA(3, 17) << '\n';
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