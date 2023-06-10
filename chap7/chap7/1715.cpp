/*
* 23-05-23 15:28
* 
* 1�� �õ��� 1�ð� �ҿ�� ����
* 
* 2�� �õ�: 22-05-25 23:40 ~ 24:04
* 
* - ������ ���ٹ��� ������ �־���. 
* - ���� ���� �� ī����̸� �����س����� ���� ���� ����̾���...
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int card[100001];

int minCompareNum() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		pq.push(card[i]);
	}
	int ret = 0;
	for (int i = 1; i <= N - 1; i++) {
		int firstPick = pq.top();
		pq.pop();
		int secondPick = pq.top();
		pq.pop();
		ret += firstPick + secondPick;
		pq.push(firstPick + secondPick);
	}
	return ret;
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	cout << minCompareNum() << "\n";

	return 0;
}

#include <algorithm>


int temp[100001];

long long minMergeNum() {
	if (N == 1) {
		return card[1];
	}
	long long ret = 0;
	int remain = N;
	while (remain > 1) {
		int deckNum;
		int deckCount = 0;
		sort(card + 1, card + 1 + remain);
		for (deckNum = 1; deckNum <= remain / 2; deckNum++) {
			temp[deckNum] = card[deckNum] + card[remain - deckNum + 1];
			ret += temp[deckNum];
			deckCount += 1;
		}
		if (remain % 2 == 1) {
			temp[deckNum] = card[deckNum];
			deckCount += 1;
		}
		for (int i = 1; i <= deckCount; i++) {
			card[i] = temp[i];
		}
		remain = deckCount;
	}
	return ret;
}

int main0(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	cout << minMergeNum() << "\n";

	return 0;
}