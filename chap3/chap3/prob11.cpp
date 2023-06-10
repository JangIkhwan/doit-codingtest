/*
* 23-05-11, https://www.acmicpc.net/problem/2164
* 14ºÐ ¼Ò¿ä
*/

#include <iostream>
#include <queue>
using namespace std;


int main(void) {
	int N;
	cin >> N;

	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		qu.push(i);
	}

	while (qu.size() != 1) {
		qu.pop();
		int front = qu.front();
		qu.pop();
		qu.push(front);
	}

	cout << qu.front() << "\n";
	return 0;
}