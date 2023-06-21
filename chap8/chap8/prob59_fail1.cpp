/*
https://www.acmicpc.net/problem/1854

23-06-15 12:12 ~ 12:58 
1차 시도 : 풀이 시간 소요...

15:07 ~ 
1차 시도 : 수정
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 987654321;

int N, M, K;
vector<pair<int, int>> graph[1001];
int dists[1001];
int touch[1001];
int prevTouch[1001];
int prevPath[1001];
bool visited[1001];
vector<pair<int, int>> cands;

void dijkstra(int start) {
	priority_queue<pair<int, int>> qu;
	for (int i = 1; i <= N; i++) {
		dists[i] = INF;
	}
	dists[start] = 0;
	for (auto cand : cands) {
		qu.push(cand);
	}
	while (!qu.empty()) {
		int distance = -qu.top().first;
		int now = qu.top().second;
		qu.pop();
		if (dists[now] < distance) continue;
		for (auto edge : graph[now]) {
			int next = edge.first;
			int nextDistance = distance + edge.second;
			if (nextDistance > prevPath[next] && nextDistance < dists[next]) { //
				dists[next] = nextDistance;
				touch[next] = now;
				qu.push(make_pair(-nextDistance, next));
				cands.push_back(make_pair(-nextDistance, next));
			}
		}
	}
}

void findKthMinDist() {
	cands.push_back(make_pair(0, 1));
	for (int phase = 1; phase <= K; phase++) {
		dijkstra(1);
		for (int i = 1; i <= N; i++) {
			prevPath[i] = dists[i];
			//prevTouch[i] = touch[i];
		}
	}
	if (dists[1] == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", dists[1]);
	}
	for (int i = 2; i <= N; i++) {
		if (dists[i] == INF) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dists[i]);
		}
	}
}

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}

	findKthMinDist();

	return 0;
}
//
//int inf = 987654321;
//
//int n, m, k;
//vector<pair<int, int>> graph[1001];
//int path[1001];
//int touch[1001];
//int prevtouch[1001];
//int prevpath[1001];
//bool visited[1001];
//vector<pair<int, int>> cands;
//
//void dijkstra0(int start) {
//	priority_queue<pair<int, int>> qu;
//	for (int i = 1; i <= n; i++) {
//		path[i] = inf;
//	}
//	path[start] = 0;
//	qu.push(make_pair(0, start));
//	while (!qu.empty()) {
//		int distance = -qu.top().first;
//		int now = qu.top().second;
//		qu.pop();
//		if (path[now] < distance) continue;
//		for (auto edge : graph[now]) {
//			int next = edge.first;
//			int nextdistance = distance + edge.second;
//			if (nextdistance > prevpath[next] && nextdistance < path[next]) {
//				path[next] = nextdistance;
//				touch[next] = now;
//				qu.push(make_pair(-nextdistance, next));
//			}
//			/*else if(nextdistance == prevpath[next] && nextdistance < path[next]) {
//				if (prevtouch[next] == now) {
//					bool check = false;
//					for (int i = 1; i <= n; i++) {
//						if (path[i] != prevpath[i]) {
//							check = true;
//							break;
//						}
//					}
//					if (!check) continue;
//				}
//				path[next] = nextdistance;
//				touch[next] = now;
//				qu.push(make_pair(-nextdistance, next));
//			}*/
//		}
//	}
//}
//
//void findkthmindist0() {
//	for (int phase = 1; phase <= k; phase++) {
//		dijkstra0(1);
//		for (int i = 1; i <= n; i++) {
//			prevpath[i] = path[i];
//			prevtouch[i] = touch[i];
//		}
//	}
//	if (path[1] == 0) {
//		printf("-1\n");
//	}
//	else {
//		printf("%d\n", path[1]);
//	}
//	for (int i = 2; i <= n; i++) {
//		if (path[i] == inf) {
//			printf("-1\n");
//		}
//		else {
//			printf("%d\n", path[i]);
//		}
//	}
//}
//
