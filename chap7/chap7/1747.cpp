/*
* 1차 시도
* 23-05-26 15:23 ~ 15:51
* - 30분 소요.
* - 각 정수가 소수인지 일일이 판별하는 것은 시간초과를 발생시킴
* - 빠르게 소수인지 알려면 에라토스테네스의 체를 이용해야 함.
* - N이 최대일 때 값을 알아보기 위해서 별도의 함수를 만들어봄. 
* 이를 통해서 메모리를 더 절약할 수 있었음
* 
*/
#include <iostream>
#include <vector>
#define MAX_PAL 1003001
using namespace std;

int N;
bool isPrime[MAX_PAL];

void findPrime() {
	for (int i = 2; i <= MAX_PAL; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= MAX_PAL; i++) {
		if (isPrime[i]) {
			for (int j = 2; i * j <= MAX_PAL; j++) {
				isPrime[i * j] = false;
			}
		}
	}
}

int minPrimePalin() {
	for (int cur = N; cur <= MAX_PAL; cur++) {
		if (isPrime[cur]) {
			vector<int> v;
			int primeNum = cur;
			while (primeNum > 0) {
				v.push_back(primeNum % 10);
				primeNum = primeNum / 10;
			}
			int size = v.size();
			bool isPelindrom = true;
			for (int i = 0; i < size / 2; i++) {
				if (v[i] != v[size - i - 1]) {
					isPelindrom = false;
				}
			}
			if (isPelindrom) {
				return cur;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;

	findPrime();
	cout << minPrimePalin() << "\n";

	return 0;
}

void minPelindrom() {
	for (int i = N; ; i++) {
		bool prime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			vector<int> v;
			int primeNum = i;
			while (primeNum > 0) {
				v.push_back(primeNum % 10);
				primeNum = primeNum / 10;
			}
			int size = v.size();
			bool isPelindrom = true;
			for (int i = 0; i < size / 2; i++) {
				if (v[i] != v[size - i - 1]) {
					isPelindrom = false;
				}
			}
			if (isPelindrom) {
				cout << i << "\n";
				break;
			}
		}
	}
}