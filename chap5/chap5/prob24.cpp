/*
* 23-05-17 20:06 ~ 20:36, https://www.acmicpc.net/problem/2023
* 
* 1���� ����
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
			dfs(newPrime, L + 1); // ���ȣ�� �� ���� ���� �� �����Ŀ� ����
		}
	}
}

int main(void) {
	cin >> N;

	int first[] = { 2, 3, 5, 7 }; // ù �ڸ��� �Ҽ��� �����ص� ��.
	for (int i = 0; i < 4; i++) {
		prime[1] = first[i];
		dfs(first[i], 2);
	}
	
	return 0;
}