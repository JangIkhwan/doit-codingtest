/*
https://www.acmicpc.net/problem/1197

23-06-20 21:46 ~ 27
1차 시도 실패
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

class UnionFind {
	int parents[10001];
public:
	UnionFind() {
		for (int i = 1; i <= 10000; i++) {
			parents[i] = i;
		}
	}
	void merge(int i, int j) {
		int root = find(i);
		parents[j] = root;
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
};

struct compare {
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		return a.first > b.first;
	}
};

int V, E;
priority_queue<pair<int, pair<int, int>> ,vector<pair<int, pair<int, int>>>, compare> pq;

int Kruskal() {
	UnionFind set;
	int edgeCount = 0;
	int treeWeight = 0;
	for(int i = 1; i<= E; i++){
		int weight = pq.top().first;
		int v1 = pq.top().second.first;
		int v2 = pq.top().second.second;
		pq.pop();
		if (set.find(v1) != set.find(v2)) {
			set.merge(v1, v2);
			treeWeight += weight;
			edgeCount += 1;
			if (edgeCount >= V - 1) {
				break;
			}
		}
	}
	return treeWeight;
}

int main(void) {
	int a, b, c;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		pq.push(make_pair(c, make_pair(a, b)));
	}

	printf("%d\n", Kruskal());

	return 0;
}