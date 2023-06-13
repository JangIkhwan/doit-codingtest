/*
https://www.acmicpc.net/problem/1948

23-06-12 16:20 ~ 17:06
1차 시도 : 틀림

17:50 ~ 18:18
1차 수정 시도 : 맞음 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> graph[10001];
int walkingTime[10001];
vector<int> previous[10001]; // 긴 경로를 구성하는 노드의 이전 노드들을 저장하는 배열
int inDegree[10001];

void walk(int start) {
	queue<int> qu;
	qu.push(start);
	for (int i = 1; i <= N; i++) {
		int now = qu.front();
		qu.pop();
		for (auto info : graph[now]) {
			int next = info.first;
			int walk = info.second;
			if (walkingTime[next] < walkingTime[now] + walk) {
				walkingTime[next] = walkingTime[now] + walk;
				previous[next].clear();
				previous[next].push_back(now);
			}
			else if (walkingTime[next] == walkingTime[now] + walk) {
				previous[next].push_back(now);
			}
			if (--inDegree[next] == 0) {
				qu.push(next);
			}
		}
	}
}

bool visited[10001];

void dfs(int cur, int& roadCount) {
	visited[cur] = true;
	for (int prev : previous[cur]) {
		//cout << "road " << cur << ", " << prev << "\n";
		roadCount++;
		if (!visited[prev]) {
			dfs(prev, roadCount);
		}
	}
}

int main(void) {
	int start, end, time;
	cin >> N;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> start >> end >> time;
		graph[start].push_back(make_pair(end, time));
		inDegree[end]++; // 위상정렬 사용시 진입차수 배열 초기화를 잊지 말기
	}

	cin >> start >> end;

	walk(start);

	int roadCount = 0;
	dfs(end, roadCount);

	cout << walkingTime[end] << "\n";
	cout << roadCount << "\n";

	return 0;
}


// 1차 시도 코드
// 문제를 잘못 이해해서 도로의 개수를 세는 로직이 잘못됨

int trace[10001];

void walk0(int start) {
	queue<int> qu;
	qu.push(start);
	for (int i = 1; i <= N; i++) {
		int now = qu.front();
		qu.pop();
		for (auto info : graph[now]) {
			int next = info.first;
			int walk = info.second;
			if (walkingTime[next] < walkingTime[now] + walk) {
				walkingTime[next] = walkingTime[now] + walk;
				trace[next] = now;
			}
			if (--inDegree[next] == 0) {
				qu.push(next);
			}
		}
	}
}

int main0(void) {
	int start, end, time;
	cin >> N;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> start >> end >> time;
		graph[start].push_back(make_pair(end, time));
		inDegree[end]++;//
	}

	cin >> start >> end;

	walk(start);

	int cityNum = 0; //
	int next = end;
	while (trace[next] > 0) {
		cityNum++;
		next = trace[next]; // while문의 제어 변수 변화시키는 것 잊지 말기
	}

	cout << walkingTime[end] << "\n";
	cout << cityNum << "\n";

	return 0;
}


