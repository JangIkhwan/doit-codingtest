/*
* https://www.acmicpc.net/problem/11047
* 
* 23-05-23 14:55 ~ 15:11
*/
#include <iostream>
using namespace std;

int main(void) {
	int N, K;
	int coin[11];

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}

	int coinNum = 0;
	for(int i = N; i >= 1; i--){
		if (coin[i] <= K) {
			coinNum += K / coin[i];
			K = K % coin[i];
			if (K == 0) {
				break;
			}
		}
	}

	cout << coinNum << "\n";

	return 0;
}