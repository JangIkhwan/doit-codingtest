/*
* 23-06-04 17:50 ~ 18:38 
* 1차 : 시간 초과...
* 
* 21:50 ~ 10:21
* 2차 : 성공
* - 때로는 간단한 접근 방법이 답을 내는 길일 수 있음...
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> trusters[10001];
bool visited[10001];

void dfs(int cur, int& cnt) {
	visited[cur] = true;
	cnt += 1;
	for (int next : trusters[cur]) {
		if (!visited[next]) {
			dfs(next, cnt);
		}
	}
}

void findPossibleTarget() {
	vector<int> result;
	int maxNum = 0;
	for (int node = 1; node <= N; node++) {
		int hackableNum = 0;
		memset(visited, 0, sizeof(visited));
		dfs(node, hackableNum);
		if (hackableNum > maxNum) {
			maxNum = hackableNum;
			result.clear();
			result.push_back(node);
		}
		else if (hackableNum == maxNum) {
			result.push_back(node);
		}
	}
	for (int node : result) {
		cout << node << " ";
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int trustee, truster;
		cin >> truster >> trustee;

		trusters[trustee].push_back(truster);
	}

	findPossibleTarget();

	return 0;
}

// 실패한 코드들

int trustNum[10001];

int getTrustNum_fail0(int cur) {
	int trusterCount = 0;
	int sum = 0;
	if (trustNum[cur] != -1) {
		return trustNum[cur];
	}
	visited[cur] = true;
	for (int truster : trusters[cur]) {
		if (!visited[truster]) {
			sum += getTrustNum_fail0(truster);
			trusterCount += 1;
		}
	}
	return trustNum[cur] = sum + trusterCount;
}

void findPossibleTarget_fail0() {
	vector<int> result;
	memset(trustNum, -1, sizeof(trustNum));
	int maxTrustNum = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		int trustNum = getTrustNum_fail0(i);
		if (trustNum > maxTrustNum) {
			maxTrustNum = trustNum;
			result.clear();
			result.push_back(i);
		}
		else if (trustNum == maxTrustNum) {
			result.push_back(i);
		}
	}
	for (int res : result) {
		cout << res << " ";
	}
}

/*
void assignTrustNum(int cur) {
	int result = 0;
	int trusteeCount = 0;
	for (trustee) {
		if (trustNum[trustee] == -1) {
			assignTrustNum(trustee);
		}
		result += trustNum[trustee];
		trusteeCount += 1
	}
	if (trusteeCount == 0) {
		trustNum[cur] = 0;
		return;
	}
	trustNum[cur] = result;
}
*/

