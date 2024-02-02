/*
* https://www.acmicpc.net/problem/9252
24-02-02 17:54 ~ 18:41

풀이방법
- A와 B의 LCS의 길이는 A의 부분문자열과 B의 부분문자열의 LCS의 길이로 구할 수 있음
- dp[i][j]를 A의 i번까지의 접두어와 B의 j번까지의 접두어의 LCS의 길이라 하자
그러면 다음과 같음.

입력 예시
acaykp
capcak

  c a p c a k
a 0 1 1 1 1 1
c 0 1 1 2 2 2
a 0 1 1 2 3 3
y 0 1 1 2 3 3
k 0 1 1 2 2 4
p 0 1 2 2 2 4

A[i] == B[j] 이면 dp[i][j] = dp[i - 1][j - 1] + 1
A[i] != B[j]이면 dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) 

- dp 배열을 통해 LCS 문자열을 구하려면 마지막 문자부터 찾아나가면 됨.
위의 점화식을 통해서 A[i] == B[j]이면 대각선으로 이동하고, 
반대의 경우라면 왼쪽과 위쪽 중 큰 값이 있는 쪽으로 이동하면 됨.

새롭게 알게 된 점
- 문자열에 대한 동적계획법은 이와 같이 푸는 경우가 많다고 함

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

string A, B;
int dp[1001][1002];
char result[1002];

void lcs() {
	int last_i, last_j;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	int lcsLen = dp[A.length()][B.length()];
	printf("%d\n", lcsLen);
	if (lcsLen > 0) {
		result[lcsLen] = '\0';
		lcsLen -= 1;
		int i = A.length();
		int j = B.length();
		while (i >= 1 && j >= 1) {
			if (A[i - 1] == B[j - 1]) {
				result[lcsLen] = A[i - 1];
				lcsLen--;
				i--;
				j--;
			}
			else {
				if (dp[i][j - 1] > dp[i - 1][j]) {
					j--;
				}
				else {
					i--;
				}
			}
		}
		printf("%s", result);
	}
}

int main(void) {
	cin >> A >> B;
	lcs();
	return 0;
}
