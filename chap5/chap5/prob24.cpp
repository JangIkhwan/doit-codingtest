/*
* 23-05-17 20:06 ~ 20:36, https://www.acmicpc.net/problem/2023
* 
* 1차에 성공
*/
#include <iostream>
#include <cmath>
using namespace std;

int prime[9];
int N;

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void dfs(int prevPrime, int L) {
	if (L == N + 1) {
		for (int i = 1; i <= N; i++) {
			cout << prime[i];
		}
		cout << "\n";
		return;
	}
	for (int next = 1; next <= 9; next++) {
		int newPrime = prevPrime * 10 + next;
		if (isPrime(newPrime)) {
			prime[L] = next;
			dfs(newPrime, L + 1); // 재귀호출 시 제어 변수 값 증가식에 주의
		}
	}
}

int main(void) {
	cin >> N;

	int first[] = { 2, 3, 5, 7 }; // 첫 자리는 소수로 지정해도 됨.
	for (int i = 0; i < 4; i++) {
		prime[1] = first[i];
		dfs(first[i], 2);
	}
	
	return 0;
}