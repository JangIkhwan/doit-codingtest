#include <iostream>
using namespace std;

bool isPrime[1000001];

int main(void) {
	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			for (int j = 2; i * j <= N; j++) {
				isPrime[i * j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) { // 문제에서 원하는 답에 주의!
		if (isPrime[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}