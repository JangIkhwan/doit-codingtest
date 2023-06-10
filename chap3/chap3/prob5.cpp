/*
23-05-08, https://www.acmicpc.net/problem/2018
*/
#include <iostream>
using namespace std;

int main(void) {
	int N; 
	cin >> N;

	int s = 1;
	int e = 1;
	int sum = 1;
	int cnt = 0;
	while (e < N || sum >= N) {
		if (sum == N) {
			cnt++;
		}
		if (sum < N) {
			e++;
			sum += e;
		}
		else {
			sum -= s;
			s++;
		}
	}

	cout << cnt << "\n";

	return 0;
}