/*
* https://www.acmicpc.net/problem/13023
* 
* 23-05-29 15:17~ 16:08
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> friends[2000];
bool checked[2000];
bool visited[2000];
int distances[2000];

void dfs(int cur, vector<int>& endPoints) {
	bool isLastNode = true;
	checked[cur] = true;
	visited[cur] = true;
	for (int next : friends[cur]) {
		if (!visited[next]) {
			isLastNode = false;
			distances[next] = distances[cur] + 1;
			dfs(next, endPoints);
		}
	}
	if (isLastNode) {
		endPoints.push_back(cur);
	}
}

void findFarthestNode(int& endPoint, int& dist) {
	endPoint = -1;
	dist = 0;
	for (int i = 0; i < N; i++) {
		if (distances[i] > dist) {
			dist = distances[i];
			endPoint = i;
		}
	}
}

int judge() {
	for (int start = 0; start < N; start++) {
		if (!checked[start]) {
			vector<int> endPoints;
			vector<int> temp;

			memset(visited, 0, sizeof(visited));
			memset(distances, 0, sizeof(distances));
			dfs(start, endPoints);

			int farthest = -1;
			int longDist = 0;
			for (int end : endPoints) {
				int endPoint;
				int dist;
				memset(visited, 0, sizeof(visited));
				memset(distances, 0, sizeof(distances));

				dfs(end, temp);
				findFarthestNode(endPoint, dist);
				if (dist > longDist) {
					farthest = endPoint;
					longDist = dist;
				}	
			}
			if (longDist >= 4) { // 
				return 1;
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	cout << judge() << "\n";

	return 0;
}

void dfs0(int cur) {
	checked[cur] = true;
	visited[cur] = true;
	for (int next : friends[cur]) {
		if (!visited[next]) {
			distances[next] = distances[cur] + 1;
			dfs0(next);
		}
	}
}

int findFarthestNode0() {
	int ret = -1;
	int farthest = 0;
	for (int i = 0; i < N; i++) {
		if (distances[i] > farthest) {
			farthest = distances[i];
			ret = i;
		}
	}
	return ret;
}

int judge0() {
	for (int start = 0; start < N; start++) {
		if (!checked[start]) {
			memset(visited, 0, sizeof(visited));
			memset(distances, 0, sizeof(distances));
			dfs0(start);
			int farthest = findFarthestNode0();

			memset(visited, 0, sizeof(visited));
			memset(distances, 0, sizeof(distances));
			dfs0(farthest);
			farthest = findFarthestNode0();
			if (distances[farthest] >= 4) { // 
				return 1;
			}
		}
	}
	return 0;
}
