/*
https://www.acmicpc.net/problem/1456

23-05-31 11:26 ~ 12:06

11차 시도 틀림

23-05-31 12:20 ~ 12:36 , 14:40 ~ 15:36 
 
2차 시도
*/

#include <iostream>
#include <cmath>
#define MAX 10000001
using namespace std;

long long A, B;
bool isPrime[MAX];

long long countApproxPrime() { //
	for (int i = 2; i < MAX; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= sqrt(MAX - 1); i++) {
		if (isPrime[i]) {
			for (int j = 2; i * j < MAX; j++) {
				isPrime[i * j] = false;
			}
		}
	}
	long long cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			long long powPrime = i * i;
			while (powPrime <= B) {
				if (powPrime >= A) {
					cnt++;
				}
				powPrime = powPrime * i;
			}
		}
	}
	return cnt;
}


int main(void) {
	cin >> A >> B;

	cout << countApproxPrime() << "\n";

	return 0;
}


// 시간 초과가 일어날 것으로 보임
long long countApproxPrime0() { //
	long long cnt = 0;
	int routeB = sqrt(B);
	int maxNum = (routeB < MAX) ? routeB : routeB - 1;
	for (int i = 2; i <= maxNum; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= maxNum; i++) {
		if (isPrime[i]) {
			for (int j = 2; i * j <= maxNum; j++) {
				isPrime[i * j] = false;
			}

			//bool isChanged = false;

			long long powPrime = i * i;
			while (powPrime <= B) {
				if (powPrime >= A) {
					cnt++;

					//isChanged = true;
				}
				powPrime *= i;
			}

			//if (isChanged)
			//	cout << "i : " << i << ", cnt: " << cnt << "\n";
		}

	}
	return cnt;
}

long long countApproxPrime1() {
	int maxNum = sqrt(B);
	int primeCount = 0;
	for (int i = 2; i <= maxNum; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= maxNum; i++) {
		if (isPrime[i]) {
			primeCount += 1;
			for (int j = 2; i * j <= maxNum; j++) {
				isPrime[i * j] = false;
			}
		}
	}

	long long cnt = 0;
	int i = 2;
	int left = 2;
	int right = maxNum;
	int leftOffset;
	int rightOffset = 0;
	while (left <= right) {
		left = 2;
		leftOffset = 0;
		while (pow(left, i) <= B && (!isPrime[left] || pow(left, i) < A)) { //
			left++;
			if (isPrime[left - 1]) {
				leftOffset++;
			}
		}
		while (pow(right, i) >= A && (!isPrime[right] || pow(right, i) > B)) { //
			right--;
			if (isPrime[right + 1]) {
				rightOffset++;
			}
		}
		if (left > right) break; //

		cnt += primeCount - (leftOffset + rightOffset);
		i += 1;
	}
	return cnt;
}