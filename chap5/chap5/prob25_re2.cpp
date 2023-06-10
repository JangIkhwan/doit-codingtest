/*
* 23-05-29 19:49
* - ��Ʈ�� ���� �ڵ带 �ۼ��غ�
* - �� ������ dfs�� ���� 5���� ��尡 ���ӵǴ��� Ȯ���ϴ� ������ ������ �� ����.
* - dfs�� ��� ��带 ���������� �ؼ� �õ��ؾ� ��.
* 
* - �׷��� Ʋ�ȴٰ� ����!!!
* - �˰��� dfs()���� �湮�� ��忡 �����Ǵ� visited[]�� ���� false�� �ٲپ�� ��.
* - �� ������ ���� ���� �ݷ� ������. 
* - ���� ��� �湮 ������ ���� ���踦 ��ã�� ���� �����Ƿ� ������ �湮�� ��嵵 �ٽ� ����ؾ���. 
* - ���� ���� : https://www.acmicpc.net/board/view/106972
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