/*
* https://www.acmicpc.net/problem/1167
* 
* 1차 시도 37분 소요로 실패
* 
* 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V;
vector<pair<int, int>> tree[100001];
int distances[100001];
bool visited[100001];

pair<int, int>* treeHeight(int cur, int prevTerminal){
	pair<int, int>* ret = new pair<int, int>(cur, 0); //
	bool isTerminal = true;
	visited[cur] = true;
	for (auto edge : tree[cur]) {
		int next = edge.first;
		int dist = edge.second;
		if (!visited[next]) {
			pair<int, int>* temp = treeHeight(next, prevTerminal);
			temp->second += dist;
			if (prevTerminal == -1) {
				if (temp->second > ret->second) {
					delete ret;
					ret = temp;
				}
			}
			else {
				if (temp->first != prevTerminal && temp->second > ret->second) {
					delete ret; 
					ret = temp;
				}
			}
			isTerminal = false;
		}
	}
	if (isTerminal) {
		return new pair<int, int>(cur, 0); //
	}
	return ret;
}   

pair<int, int>* treeDiameter() {
	
	pair<int, int>* ret = pair<int, 
	for () {
		start = treeHeight(1, -1);
		memset(visited, 0, sizeof(visited));
		end = treeHeight(1, start->first);
		ret->first = max(ret->first, start->second + end->second);
		ret->second = max(ret->second, max(start->second, end->second));
	}
	
	return ret;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	for (int i = 1; i <= V; i++) {
		int start, end, dist;
		cin >> start;
		while (true) {
			cin >> end;
			if (end == -1) {
				break;
			}
			cin >> dist;
			tree[start].push_back(make_pair(end, dist));
		}
	}

	cout << treeDiameter() << "\n";

	return 0;
}

pair<int, int>* treeHeight1(int cur, int prevTerminal) {
	pair<int, int>* ret = new pair<int, int>(cur, 0); //
	bool isTerminal = true;
	visited[cur] = true;
	for (auto edge : tree[cur]) {
		int next = edge.first;
		int dist = edge.second;
		if (!visited[next]) {
			pair<int, int>* temp = treeHeight1(next, prevTerminal);
			temp->second += dist;
			if (prevTerminal == -1) {
				if (temp->second > ret->second) {
					delete ret;
					ret = temp;
				}
			}
			else {
				if (temp->first != prevTerminal && temp->second > ret->second) {
					delete ret;
					ret = temp;
				}
			}
			isTerminal = false;
		}
	}
	if (isTerminal) {
		return new pair<int, int>(cur, 0); //
	}
	return ret;
}

int treeDiameter1() {
	pair<int, int>* start, * end;

	start = treeHeight1(1, -1);
	memset(visited, 0, sizeof(visited));
	end = treeHeight1(1, start->first);

	return start->second + end->second;
}

void treeDiameter0(int start) {
	queue<int> qu;
	qu.push(start);
	distances[start] = 0;
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		visited[cur] = true;
		for (auto edge : tree[cur]) {
			int next = edge.first;
			int dist = edge.second;
			if (!visited[next]) {
				qu.push(next);
				distances[next] = distances[cur] + dist;
			}
		}
	}
}


void bfs0(int start, bool visited[], bool leafCands[]) {
	queue<int> qu;
	qu.push(start);
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		visited[cur] = true;
		bool isFinal = true;
		for (auto edge : tree[cur]) {
			int next = edge.first;
			if (!visited[next]) {
				qu.push(next);
				isFinal = false;
			}
		}
		if (isFinal) {
			leafCands[cur] = true;
		}
	}
}