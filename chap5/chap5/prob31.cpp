/*
 23-05-30 21:06~
 2차 시도 : 40분 경과로 실패
 
23-05-31 10:50
풀이를 보고 코드를 작성해봄.
 
 - 이분 탐색 아이디어를 떠올리기가 상당히 어려움
 범위가 너무 클 때는 이분탐색이 아닐까 생각해보기...
 - 이분 탐색을 할 때 정렬된 자료에서 어떤 값을 찾을지 선정해야 함.
 정렬된 값은 미리 주어지지 않고 동적으로 계산될 수 있음.
 - 이 문제의 경우에는 k번째 수를 찾아야 하므로 자기 자신보다 작은 수의 개수가 k-1개인 수를 찾아야 함.
 i번째 행에서 K보다 작은 수의 개수는 K / i개임.
 - 이 문제를 풀 때 변수의 범위에 유의해야 함.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

int findKthNum() {
	int lo = 0;
	int hi = K + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 1; i <= min(K, N); i++) { // 여기가 문제! 행의 개수는 N을 초과할 수 없음.
			cnt += min(mid / i, N);
		}
		if (cnt < K) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return hi;
}

int main(void) {
	cin >> N >> K;

	cout << findKthNum() << "\n";

	return 0;
}

