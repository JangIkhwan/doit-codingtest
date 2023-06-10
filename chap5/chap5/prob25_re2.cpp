/*
* 23-05-29 19:49
* - 힌트를 보고 코드를 작성해봄
* - 이 문제는 dfs를 통해 5개의 노드가 연속되는지 확인하는 것으로 생각할 수 있음.
* - dfs는 모든 노드를 시작점으로 해서 시도해야 함.
* 
* - 그래도 틀렸다고 나옴!!!
* - 알고보니 dfs()에서 방문한 노드에 대응되는 visited[]의 값을 false로 바꾸어야 함.
* - 그 이유는 다음 글의 반례 때문임. 
* - 다음 노드 방문 순서에 따라서 관계를 못찾을 수도 있으므로 이전에 방문한 노드도 다시 고려해야함. 
* - 다음 참고 : https://www.acmicpc.net/board/view/106972
* - 
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> friends[2000];
bool visited[2000];
bool founded;

void dfs(int cur, int L) {
	if (L >= 5) {
		founded = true;
		return;
	}
	if (founded) {
		return;
	}
	visited[cur] = true;
	for (int next : friends[cur]) {
		if (!visited[next]) {
			dfs(next, L + 1);
		}
	}
	visited[cur] = false; //
}

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int start = 0; start < N; start++) {
		//memset(visited, 0, sizeof(visited));
		dfs(start, 1);
		if (founded) {
			break;
		}
	}
	if (founded) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}