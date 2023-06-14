/*
* 23-06-05 14:34 ~ 15:13 ~ 15:26
* 실패...
* 
* 16:00 ~ 17:30
* 2차 시도 성공...
* - 그동안 틀렸던 이유는 변수를 초기화하지 않았기 때문임
* - 주의! 테스트 케이스 별로 그래프를 입력받을 때, 
* 그래프를 저장하는 벡터가 전역변수로 선언되어 있다면 초기화해야함에 유의해야 함!
*/

/*

반례 1 >

1
4 4
1 2
2 3
3 4
1 4
NO

*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[20001];
bool visited[20001];

bool judgeBipartiteGraph(int start) {
	int set[20001];
	queue<int> qu;
	visited[start] = true;
	set[start] = 0;  
	qu.push(start);
	while (!qu.empty()) {
		int node = qu.front(); 
		qu.pop();
		int setNum = (set[node] == 1) ? 0 : 1;
		for (int next : graph[node]) {
			if (!visited[next]) {
				visited[next] = true;
				set[next] = setNum;
				qu.push(next);
			}
			else {
				if (set[next] == set[node]) {
					return false;
				}
			}
		}
	}
	return true;
}

int main(void) {
	int K;
	cin >> K;
	while (K--) {
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= E; i++) {
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}
		bool check = true;
		memset(visited, 0, sizeof(visited));
		for (int start = 1; start <= V; start++) {
			if (visited[start]) {
				continue;
			}
			if (judgeBipartiteGraph(start) == false) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		for (int i = 1; i <= V; i++) { // 이 부분을 잊지 말자...!!!!
			graph[i].clear();
		}
	}

	return 0;
}

// 실패한 코드들
void judgeBipartiteGraph1(int start) {
	int set[20001];
	queue<int> qu;
	visited[start] = true;
	set[start] = 0;
	qu.push(start);
	while (!qu.empty()) {
		int node = qu.front();
		qu.pop();
		int setNum = (set[node] == 1) ? 0 : 1;
		for (int next : graph[node]) {
			if (!visited[next]) {
				visited[next] = true;
				set[next] = setNum;
				qu.push(next);
			}
			else {
				if (set[next] == set[node]) {
					cout << "NO";
					return;
				}
			}
		}
	}
	cout << "YES";
}

void judgeBipartiteGraph0(int start) {
	int set[20001];
	int setNum = 0;
	queue<int> qu;

	visited[start] = true;
	set[start] = setNum;
	qu.push(start);
	while (!qu.empty()) {
		int node = qu.front();
		qu.pop();
		setNum = (setNum == 1) ? 0 : 1;
		for (int next : graph[node]) {
			if (!visited[next]) {
				qu.push(next);
				visited[next] = true;
				set[next] = setNum;
			}
			else {
				if (set[next] == set[node]) {
					cout << "NO";
					return;
				}
			}
		}
	}
	cout << "YES";
}

