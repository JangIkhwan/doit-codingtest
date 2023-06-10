/*
* 23-05-25 10:11~11:00 1차시도 실패.
* 
* 2차시도 : 11:34 ~ 
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> pos_pq;
priority_queue<int, vector<int>, greater<int>> neg_pq;

int maxSum() {
	int ret = 0;
	while (!pos_pq.empty()) {
		int firstPick = pos_pq.top();
		pos_pq.pop();
		int secondPick;
		if (!pos_pq.empty()) {
			secondPick = pos_pq.top();
			pos_pq.pop();
		}
		else {
			ret += firstPick;
			break;
		}

		if (secondPick == 1) {
			ret += firstPick + secondPick;
		}
		else {
			ret += firstPick * secondPick;
		}
	}
	while (!neg_pq.empty()) {
		int firstPick = neg_pq.top();
		neg_pq.pop();
		int secondPick;
		if (!neg_pq.empty()) {
			secondPick = neg_pq.top();
			neg_pq.pop();
		}
		else {
			secondPick = 1;
		}
		
		ret += firstPick * secondPick;
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		if (num > 0) {
			pos_pq.push(num);
		}
		else {
			neg_pq.push(num);
		}
	}

	cout << maxSum() << "\n";

	return 0;
}


#define NONE - 10000
priority_queue<int> pq;

int maxSum0() {
	int ret = 0;
	bool zeroExist = false;
	while (!pq.empty()) {
		int firstPick = pq.top();
		pq.pop();
		int secondPick;
		if (!pq.empty()) {
			secondPick = pq.top();
			pq.pop();
		}
		else {
			secondPick = NONE;
		}

		if (secondPick == NONE) {
			if (!zeroExist)
				ret += firstPick;
			break;
		}

		if (firstPick == 0 || secondPick == 0) {
			if (!pq.empty()) {
				ret += firstPick + secondPick;
				zeroExist = true;
			}
			else {
				if (firstPick > 0) {
					ret += firstPick;
				}
			}
		}
		else if (firstPick == 1 || secondPick == 1) {
			ret += firstPick + secondPick;
		}
		else {
			ret += firstPick * secondPick;
		}
	}
	return ret;
}
