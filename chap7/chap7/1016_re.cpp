/*
* 23-06-01 21:37 ~ 22:14
* 1�� �õ� : 37�� ����� ����
*/
#include <iostream>
using namespace std;

int countNonSquareNum() {
	for (i = minVal; i <= maxVal; i++) {
		for (j = 2; j < minVal; j++) {
			if (i % (j * j) == 0) {
				cnt++;
				break;
			}
		}
	}
	return 0;
}

int main(void) {
	return 0;
}