/*
*  https://www.acmicpc.net/problem/13023
* 23-05-17 21:19 ~ 21:43
* 1차시도 실패 : 시간초과
* 
* 23-05-18 11:06 ~ 12:24
* 2차시도 : 실패
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> friends[2000];
bool visited[2000];
bool checked[2000];

int findRelation(int cur, int picked) {
	if (picked >= N) {
		return 1;
	}

	int ret = 0;
	checked[cur] = true;
	for (auto next : friends[cur]) {
		if (!checked[next]) {
			ret = max(ret, findRelation(next, picked + 1));
		}
	}
	checked[cur] = false;
	return ret;
}

void dfs(int cur, vector<int>& elems) {
	visited[cur] = true;
	elems.push_back(cur);
	int friendNum = friends[cur].size();
	for (int i = 0; i < friendNum; i++) {
		int next = friends[cur][i];
		if (!visited[next]) {
			dfs(next, elems);
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		friends[p1].push_back(p2);
		friends[p2].push_back(p1);
	}

	int result = 0;
	for (int start = 0; start < N; start++) {
		if (!visited[start]) {
			vector<int> elems;
			dfs(start, elems);
			if (elems.size() >= 5) {
				for (auto e : elems) {
					result = max(result, findRelation(e, 0));
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}

bool isFriend[2000][2000];

int findRelation0(int cur, int toPick) {
	if (toPick == 0) {
		return 1;
	}

	int ret = 0;
	checked[cur] = true;
	for (int next = 0; next < N; next++) { //
		if (!checked[next] && isFriend[cur][next]) {
			ret = max(ret, findRelation0(next, toPick - 1));
			checked[next] = false;
		}
	}
	return ret;
}

int main0(void) {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		isFriend[p1][p2] = isFriend[p2][p1] = true;
	}

	int result = 0;
	for (int start = 0; start < N; start++) {
		checked[start] = true;
		result = max(result, findRelation0(start, 4));
		checked[start] = false;
	}

	cout << result << "\n";

	return 0;
}