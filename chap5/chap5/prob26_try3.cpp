/*
* 23-05-22 21:53 ~ 22:13
* 
* ������ ���� ���� ����� ���� ���� �ڵ�� ������
* �߿��� ���̵��� �� �������� ���� �Ÿ��� �� ��尡 ������ �� �����̶�� �����
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V;
vector<pair<int, int>> edges[100001];
bool visited[100001];
int distances[100001];

void dfs(int cur) {
	visited[cur] = true;
	for (auto edge : edges[cur]) {
		int next = edge.first;
		int dist = edge.second;
		if (!visited[next]) {
			distances[next] = distances[cur] + dist;
			dfs(next);
		}
	}
}

int findOnePointOfDiameter() {
	int ret = 1;
	int longestDist = distances[1];
	for (int i = 2; i <= V; i++) {
		if (distances[i] > longestDist) {
			ret = i;
			longestDist = distances[i];
		}
	}
	return ret;
}

int main(void) {
	scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		int start, end, dist;
		scanf("%d", &start);
		while (true) {
			scanf("%d", &end);
			if (end == -1) {
				break;
			}
			scanf("%d", &dist);
			edges[start].push_back(make_pair(end, dist));
		}
	}

	dfs(1);
	int onePoint = findOnePointOfDiameter();

	memset(visited, 0, sizeof(visited));
	memset(distances, 0, sizeof(distances));
	dfs(onePoint);
	int anotherPoint = findOnePointOfDiameter();

	printf("%d\n", distances[anotherPoint]);

	return 0;
}