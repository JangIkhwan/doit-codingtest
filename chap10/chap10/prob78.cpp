/*
https://www.acmicpc.net/problem/2775

23-07-26 15:29 ~ 

resident[a][b] = resident[a - 1][1] + .. + resident[a - 1][b]
= resident[a][b - 1] + resident[a - 1][b];

1 4 10
1 3 6
1 2 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int resident[15][15];

int main(void) {
	int T;
	int k, n;
	vector<int> result;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &k);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			resident[0][i] = i;
		}
		for (int floor = 1; floor <= k; floor++) {
			resident[floor][1] = 1;
			for (int room = 2; room <= n; room++) {
				resident[floor][room] = resident[floor][room - 1] + resident[floor - 1][room];
			}
		}
		result.push_back(resident[k][n]);
	}
	for (int res : result) {
		printf("%d\n", res);
	}
	return 0;
}