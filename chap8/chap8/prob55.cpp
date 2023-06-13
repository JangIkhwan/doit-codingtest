/*
https://www.acmicpc.net/problem/1948

23-06-12 16:20 ~ 17:06
1�� �õ� : Ʋ��

17:50 ~ 18:18
1�� ���� �õ� : ���� 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> graph[10001];
int walkingTime[10001];
vector<int> previous[10001]; // �� ��θ� �����ϴ� ����� ���� ������ �����ϴ� �迭
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
		inDegree[end]++; // �������� ���� �������� �迭 �ʱ�ȭ�� ���� ����
	}

	cin >> start >> end;

	walk(start);

	int roadCount = 0;
	dfs(end, roadCount);

	cout << walkingTime[end] << "\n";
	cout << roadCount << "\n";

	return 0;
}


// 1�� �õ� �ڵ�
// ������ �߸� �����ؼ� ������ ������ ���� ������ �߸���

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
		next = trace[next]; // while���� ���� ���� ��ȭ��Ű�� �� ���� ����
	}

	cout << walkingTime[end] << "\n";
	cout << cityNum << "\n";

	return 0;
}


