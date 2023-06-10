/*
* 23-05-25 15:01
*/
#include <iostream>
#include <cmath>
using namespace std;

int A, B;
bool isPrime[10000001];

int countApproxPrime() {
	int primeNum = 0;
	for (int i = 2; i * i <= B; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i * i <= B; i++) {
		if (isPrime[i]) {
			primeNum += 1;
			for (int j = 2; i * j <= B; j++) {
				isPrime[i * j] = false;
			}
		}
	}

	int ret = 0;
	int lo = 2;
	int hi = sqrt(B);
	int expo = 2;
	int lowFoundNum = 0;
	int hiFoundNum = 0;
	while (true) { // ??
		while(!isPrime[lo] || (isPrime[lo] && pow(lo, expo) < A)) {
			lo++;
			if (isPrime[lo]) {
				lowFoundNum++;
			}
		}
		while(!isPrime[hi] || (isPrime[hi] && pow(hi, expo) > B)) {
			hi--;
			if (isPrime[hi]) {
				hiFoundNum++;
			}
		}
		if (primeNum - (lowFoundNum + hiFoundNum - 2) <= 0) break;
		ret += primeNum - (lowFoundNum + hiFoundNum - 2);
		expo += 1;
	}

	return ret;
}

int main(void) {
	cin >> A >> B;
	
	cout << countApproxPrime() << "\n";

	return 0;
}