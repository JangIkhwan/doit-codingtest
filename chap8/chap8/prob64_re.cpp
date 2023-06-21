/*
23-06-21 18:30 ~ 17:00
����

�ݷ� : https://www.acmicpc.net/board/view/90566
�Է�
5 5
1 4 3
2 3 3
4 3 5
2 1 6
4 5 9

���� ���
17

����
20

21:30 ~ 22:40
�ð��� �鿩�� �����غ� ��� ������
������ ���Ͽ� ���ε带 �߸� �����߱� ������.

����ϱ�
- ���Ͽ� ���ε� ������ �ٷ� �˱�
- �켱���� ť�� ���� ������ �������� ������ ���� ū ���� ���� �������� ���ĵ�
- �켱���� ť�� ���� �����̳� �迭�� ���� ������ �����Ϸ���  operator <�� �����ϰų� 
operator() �Լ��� ���� ���� ���� ����ü�� �ۼ��ؾ� �� 
���� : https://zoosso.tistory.com/993
- operator <�� ������ �� �񱳿��� ��ȣ�� �����ϸ� �ȵ�! ���� : https://gusdnr69.tistory.com/99
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
	void merge(int i, int j) { // ���Ͽ� ���ε忡�� merge �Լ��� �����ϴ� ����� ����� ������� ������...
		int u = find(i);
		int v = find(j);
		if (u != v) { 
			parents[v] = u; // ��Ʈ���� ���ؼ� ��Ʈ�� ���� �ٸ� ��Ʈ�� �ٲٴ� ���� ����Ʈ��!
		}
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
};
 
struct Edge {  // pair ��ü�� ����ϸ� �򰥸��� ���� �Ǽ��� ���� �� ����
	int weight, v1, v2;
	bool operator<(const Edge a) const{ // �켱���� ť�� �����ϰų� �迭�� ������ �� �� �Լ��� �������̵��ؾ� ��
		if (weight > a.weight) { // �񱳿��� ��ȣ�� ���� �� invalid comparator ������ �߻��ϴ� �����ؾ� ��!!
			return true;
		}
		return false;
	}
};

int V, E;
priority_queue <Edge> pq; // �켱���� ť�� ������������ �����ϴ� ���� �⺻�̶� ū ���� ���� ����. ����ü�� ���� �����ϴ� ���� ����
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
