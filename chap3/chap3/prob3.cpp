/*

*/
#include <iostream>
using namespace std;

int sum[100001];
int result[100001];

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		sum[i] = k + sum[i - 1];
	}

	for (int m = 1; m <= M; m++) {
		int i, j;
		cin >> i >> j;
		result[m] = sum[j] - sum[i - 1];
	}

	for (int i = 1; i <= M; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}