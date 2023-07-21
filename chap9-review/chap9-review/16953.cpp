/*
23-07-11, 21:06 ~ 

끝자리가 1이면 10으로 나누고, 끝자리가 짝수이면 2로 나누기? 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	int A, B;
	int operCount = 0;

	scanf("%d %d", &A, &B);
	while (B > A) {
		if (B % 10 == 1) {
			B = B / 10;
		}
		else if (B % 2 == 0) {
			B = B / 2;
		}
		else { 
			break;
		}
		operCount += 1;
	}
	if (A == B) {
		printf("%d\n", operCount + 1);
	}
	else {
		printf("-1\n");
	}

	return 0;
}
