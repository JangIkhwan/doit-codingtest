/*
https://www.acmicpc.net/problem/1414

16:38
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int weight, v1, v2;
	bool operator < (const Edge tg) const {
		return weight > tg.weight;
	}
};

class DisjointSet {
	int parents[51];
public:
	DisjointSet(){
		for (int i = 1; i <= 50; i++) {
			parents[i] = i;
		}
	}
	void merge(int i, int j) {
		int u = find(i);
		int v = find(j);
		if (u != v) {
			parents[u] = v;
		}
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
};

int N;
priority_queue<Edge> pq;

int Kruskal() {
	DisjointSet set;
	int lengthToDonate = 0;
	int edgeCount = 0;
	while (edgeCount < N - 1) {  // 추후에 리팩토링 가능
		if (pq.empty()) { // 중간에 큐가 비면 모두 연결되지 않음
			return -1;
		}
		int weight = pq.top().weight;
		int v1 = pq.top().v1;
		int v2 = pq.top().v2;
		pq.pop();
		if (set.find(v1) != set.find(v2)) {
			set.merge(v1, v2);
			edgeCount += 1;
		}
		else {
			lengthToDonate += weight;
		}
	}
	while (!pq.empty()) {
		lengthToDonate += pq.top().weight;
		pq.pop();
	}
	//if (edgeCount == N - 1) {
		return lengthToDonate;
	//}
	//return -1;
}


int main(void) {
	char ch;
	int length;
	scanf("%d", &N);
	getchar(); // 문자를 입력받을 때 '\n'을 처리해야 함 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%c", &ch);
			if (ch == '0') continue;
			if (ch >= 'a' && ch <= 'z') {
				length = (int)(ch - 'a') + 1;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				length = (int)(ch - 'A') + 27;
			}

			pq.push({ length, i, j });
		}
		if (i != N) {
			getchar(); 
		}
	}

	printf("%d\n", Kruskal());

	return 0;
}