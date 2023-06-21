/*
23-06-21 18:30 ~ 17:00
실패

반례 : https://www.acmicpc.net/board/view/90566
입력
5 5
1 4 3
2 3 3
4 3 5
2 1 6
4 5 9

현재 출력
17

정답
20

21:30 ~ 22:40
시간을 들여서 수정해본 결과 성공함
문제는 유니온 파인드를 잘못 구현했기 때문임.

기억하기
- 유니온 파인드 구현을 바로 알기
- 우선순위 큐는 정렬 기준을 지정하지 않으면 가장 큰 값이 먼저 나오도록 정렬됨
- 우선순위 큐의 정렬 기준이나 배열의 정렬 기준을 설정하려면  operator <를 선언하거나 
operator() 함수를 갖는 정렬 기준 구조체를 작성해야 함 
참고 : https://zoosso.tistory.com/993
- operator <를 구현할 때 비교에서 등호를 포함하면 안됨! 참고 : https://gusdnr69.tistory.com/99
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

class UnionFind {
	int parents[100001];
public:
	UnionFind() {
		for (int i = 1; i <= 10000; i++) {
			parents[i] = i;
		}
	}
	void merge(int i, int j) { // 유니온 파인드에서 merge 함수를 구현하는 방법을 제대로 기억하지 못했음...
		int u = find(i);
		int v = find(j);
		if (u != v) { 
			parents[v] = u; // 루트끼리 비교해서 루트의 값을 다른 루트로 바꾸는 것이 포인트임!
		}
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
};
 
struct Edge {  // pair 객체만 사용하면 헷갈리고 구현 실수가 있을 수 있음
	int weight, v1, v2;
	bool operator<(const Edge a) const{ // 우선순위 큐에 저장하거나 배열을 정렬할 때 이 함수를 오버라이딩해야 함
		if (weight > a.weight) { // 비교에서 등호를 포함 시 invalid comparator 오류가 발생하니 주의해야 함!!
			return true;
		}
		return false;
	}
};

int V, E;
priority_queue <Edge> pq; // 우선순위 큐는 내림차순으로 정렬하는 것이 기본이라 큰 값이 먼저 나옴. 구조체를 따로 선언하는 것이 좋음
UnionFind set;

int Kruskal() {	
	int treeWeight = 0;
	int edgeCount = 0;
	while(edgeCount < V - 1) {
		int weight = pq.top().weight;
		int v1 = pq.top().v1;
		int v2 = pq.top().v2;
		pq.pop();
		if (set.find(v1) != set.find(v2)) {
			//printf("merge : %d %d\n", v1, v2);
			set.merge(v1, v2);
			treeWeight += weight;
			edgeCount += 1;
		}
	}
	return treeWeight;
}

int main(void) {
	int a, b, c;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &a, &b, &c); //
		pq.push({ c, a, b });
	}

	printf("%d", Kruskal());
	return 0;
}


/*
* class UnionFind {
	int parents[100001];
public:
	UnionFind() {
		for (int i = 1; i <= 10000; i++) {
			parents[i] = i;
		}
	}
	void merge(int i, int j) { //
		int root1 = find(i);
		int root2 = find(j);
		if (root1 != root2) {
			parents[j] = root1;
		}
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
};

int V, E;
priority_queue <pair<long long, pair<int, int>>> pq; //

int Kruskal() {
	UnionFind set;
	int treeWeight = 0;
	int edgeCount = 0;
	while(edgeCount < V -1) {
		long long weight = -pq.top().first; //
		int v1 = pq.top().second.first;
		int v2 = pq.top().second.second;
		pq.pop();
		if (set.find(v1) != set.find(v2)) {
			//printf("merge : %d %d\n", v1, v2);
			set.merge(v1, v2);
			treeWeight += weight;
			edgeCount += 1;
		}
	}
	return treeWeight;
}

int main(void) {
	int a, b;
	long long c;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %lld", &a, &b, &c); //
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		pq.push(make_pair(-c, make_pair(a, b)));
	}

	printf("%d", Kruskal());
	return 0;
}
*/
/*
class UnionFind {
	int parents[100001];
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

int V, E;
priority_queue <pair<int, pair<int, int>>> pq;

int Kruskal() {
	UnionFind set;
	int treeWeight = 0;
	int edgeCount = 0;
	for (int i = 1; i <= E; i++) {
		int weight = -pq.top().first;
		int v1 = -pq.top().second.first;
		int v2 = -pq.top().second.second;
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
		pq.push(make_pair(-c, make_pair(-a, -b)));
	}

	printf("%d", Kruskal());
	return 0;
}
*/
