/*
23-05-08, https://www.acmicpc.net/problem/11660
*/
#include <iostream>
using namespace std;

int sum[1025][1025];
int result[100001];

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			int cell;
			cin >> cell;
			sum[x][y] = cell + sum[x][y - 1];
		}
	}

	for (int i = 1; i <= M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x <= x2; x++) {
			result[i] += sum[x][y2] - sum[x][y1 - 1];
		}
	}

	for (int i = 1; i <= M; i++) {
		cout << result[i] << "\n";
	}
}