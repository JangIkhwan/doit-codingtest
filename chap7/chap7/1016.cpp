/*
* 23-05-27 10:02
*/

#include <iostream>
using namespace std;

long long countDividable() {
	if (hi < lo + 1) {
		return 1;
	}
	for (int i = 2; routeMax / i > routeMin / i + 1;i++) {
		countDividable(routeMin / i, routeMax / i);
	}
}

int main(void) {
	return 0;
}