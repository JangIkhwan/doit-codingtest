/*
* 1차 시도 실패...
* 23-05-26 16:03 ~ 17:00
* 
*
*/
#include <iostream>
#include <cmath>
#define MAX_NUM 10000001
using namespace std;

int A, B;
bool isPrime[MAX_NUM];

int findPrimeNum() {
	for (int i = 2; i * i <= B; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i * i <= B; i++) {
		if (isPrime[i]) {
			for (int j = 2; i * j <= B; j++) {
				isPrime[i * j] = false;
			}
		}
	}
}

int countApproxPrime() {
	int primeCount = 0;
	int ret = 0;
	int hi = B;
	int expo = 2;
	int lo = A;
	while (true) {
		while (!isPrime[hi] || pow(hi, expo) > B ) {
			hi--;
			if (hi < 2) {
				break;
			}
		}
		if (hi < 2 || pow(hi, expo) < A) {
			break; 
		}
		lo = hi;
		while (!isPrime[lo] || pow(lo, expo) > A) {
			lo--;
			if (isPrime[lo]) {
				primeCount++;
			}
			if (lo < 2) {
				break;
			}
		}
		if (isPrime[lo]) {
			primeCount++;
		}
		ret += primeCount;
		primeCount = 0;
		expo += 1;
	}
	return ret;
}

int main() {
	cin >> A >> B;

	findPrimeNum();
	cout << countApproxPrime() << "\n";

	return 0;
}

int countApproxPrime0() {
	int primeCount = 0;
	int ret = 0;
	int hi = B;
	int hiCount = 0;
	int expo = 2;
	int lo = A;
	int loCount = 0;
	while (!isPrime[lo] || lo * lo < A) {
		lo++;
		if (isPrime[lo]) {
			loCount++;
		}
	}
	for (int i = lo; i <= B; i++) {
		if (isPrime[i]) {
			primeCount++;
		}
	}
	while (true) {
		if (pow(lo, expo) > B) {
			break;
		}
		while (hi >= lo && (!isPrime[hi] || pow(hi, expo) > B)) {
			hi--;
			if (isPrime[hi]) {
				hiCount++;
			}
		}
		if (hi < lo) {
			break;
		}
		ret += primeCount - (loCount + hiCount - 2);
		expo += 1;
	}
	return ret;
}