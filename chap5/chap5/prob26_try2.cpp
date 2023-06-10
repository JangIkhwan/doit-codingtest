/*
* 23-05-22 10:00 ~ 11:39
* 실패... 스택오버플로우 발생
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int V;
vector<pair<int, int>> edges[100001];
bool visited[100001];
bool checked[100001];


int getHeight(int root) {
	if (edges[root].size() < 1) {
		return 0;
	}
	int ret = 0;
	checked[root] = true; // 스택 오버플로우의 원인은 이것을 누락했기 때문...
	for (auto edge : edges[root]) {
		int next = edge.first;
		int dist = edge.second;
		if (!visited[next] && !checked[next]) {
			ret = max(ret, getHeight(next) + dist);
		}
	}
	return ret;
}

int treeDiameter(int curRoot) {
	int ret = 0;
	int subTreeNum = edges[curRoot].size();

	visited[curRoot] = true;
	if (subTreeNum >= 1) {
		int largestHeight = 0;
		int secondLargestHeight = 0;
		vector<int> heights;

		for (int i = 0; i < subTreeNum; i++) {
			int subRoot = edges[curRoot][i].first;
			int dist = edges[curRoot][i].second;
			if (visited[subRoot]) {
				heights.push_back(dist);
				continue;
			}
			memset(checked, 0, sizeof(checked));
			int height = getHeight(subRoot) + dist;
			heights.push_back(height);
			if (largestHeight != 0 && height > largestHeight) {
				secondLargestHeight = largestHeight;
				largestHeight = height;
			}
			else if (secondLargestHeight != 0 && height > secondLargestHeight) {
				if (largestHeight == 0) {
					largestHeight = height;
				}
				else {
					secondLargestHeight = height;
				}
			}
			else {
				secondLargestHeight = height;
			}
		}
		ret = largestHeight + secondLargestHeight; 
		for (int i = 0; i < subTreeNum; i++) {
			int subRoot = edges[curRoot][i].first;
			int dist = edges[curRoot][i].second;
			if (!visited[subRoot] && heights[i] - dist > ret / 2) {
				ret = max(ret, treeDiameter(subRoot));
			}
		}
	}
	
	return ret;
}

int main(void) {
	scanf("%d", &V);
	for (int i = 1; i <= V; i++) {
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

	printf("%d\n", treeDiameter(1)); //

	return 0;
}


int getHeight0(int root) {
	if (edges[root].size() < 1) {
		return 0;
	}
	int ret = 0;
	for (auto edge : edges[root]) {
		int next = edge.first;
		int dist = edge.second;
		if (!visited[next] && !checked[next]) {
			ret = max(ret, getHeight0(next) + dist);
		}
	}
	return ret;
}

int treeDiameter0(int curRoot) {
	int ret = 0;
	int largestHeight = 0;
	int secondLargestHeight = 0;
	int firstDist, secondDist;
	vector<int> heights;
	int subTreeNum = edges[curRoot].size();

	visited[curRoot] = true;
	if (subTreeNum > 1) {
		for (int i = 0; i < subTreeNum; i++) {
			int subRoot = edges[curRoot][i].first;
			int dist = edges[curRoot][i].second;
			memset(checked, 0, sizeof(checked));
			int height = getHeight0(subRoot); // 
			heights.push_back(height);
			if (secondLargestHeight != 0 && height > largestHeight) {
				largestHeight = height;
			}
			else if (height > secondLargestHeight) {
				if (largestHeight == 0) {
					largestHeight = secondLargestHeight;
				}
				secondLargestHeight = height;
			}
		}
		ret = largestHeight + secondLargestHeight + 2; // 거리는 
		for (int i = 0; i < subTreeNum; i++) {
			int subRoot = edges[curRoot][i].first;
			if (!visited[subRoot] && heights[i] > ret / 2) {
				ret = max(ret, treeDiameter0(subRoot));
			}
		}
	}
	else if (subTreeNum == 1) {
		int subRoot = edges[curRoot][0].first;
		memset(checked, 0, sizeof(checked));
		ret = getHeight0(subRoot); //
		if (!visited[subRoot]) {
			ret = max(ret, treeDiameter0(subRoot));
		}
	}

	return ret;
}

void print() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < edges[i].size(); j++) {
			printf("(%d, %d) ", edges[i][j].first, edges[i][j].second);
		}
		printf("\n");
	}
	printf("\n");
}