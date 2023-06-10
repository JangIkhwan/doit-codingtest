/*
* 23-05-22 21:53 ~ 22:13
* 
* 교재의 문제 접근 방식을 보고 나의 코드로 구현함
* 중요한 아이디어는 한 정점에서 가장 거리가 먼 노드가 지름의 한 끝점이라는 사실임
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