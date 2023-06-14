/*
https://www.acmicpc.net/problem/1043
 
23-06-08 14:48 ~ 15:33 
1차 시도 : 틀렸음
- 틀린 이유는 다른 파티에서 진실을 들은 사람이 파티에 참석한 경우를 제대로 고려하지 않았기 때문으로 보임.

15:40 ~ 16:13
2차 시도 : 성공

생각해볼 점
- 각 파티에 참석자 집합을 구성한 후에 
진실을 아는 사람의 집합의 원소를 포함하는지 확인하면 더 간단하게 구현할 수 있음..
*/
#include <iostream>
#include <vector>
using namespace std;

class UnionSet {
private:
	int parents[51];
public:
	UnionSet() {
		for (int i = 1; i <= 50; i++) {
			parents[i] = i;
		}
	}
	int find(int i) {
		if (parents[i] == i) {
			return i;
		}
		return parents[i] = find(parents[i]);
	}
	void merge(int i, int j) {
		int p = find(i);
		parents[j] = p;
	}
};

int N, M;
vector<int> members[51];
vector<int> graph[51];
vector<int> knowers;
bool visited[51];

void dfs(int cur, UnionSet& set) {
	visited[cur] = true;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			set.merge(cur, next);
			dfs(next, set);
		}
	}
}

int maxPartyNum() {
	int ret = 0;
	UnionSet set;
	if (knowers.size() == 0) {
		return M;
	}
	int root = set.find(knowers[0]);
	for (int knower : knowers) {
		set.merge(root, knower);
	}
	for (int start : knowers) {
		dfs(start, set);
	}
	for (int party = 0; party < M; party++) {
		bool canLie = true;
		for (int member : members[party]) {
			if (set.find(member) == root) {
				canLie = false;
				break;
			}
		}
		if (canLie) {
			ret += 1;
		}
	}
	return ret;
}

int main(void) {
	cin >> N >> M;
	int num;
	int knower;
	int root;
	int member;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> knower;
		knowers.push_back(knower);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		cin >> root;
		members[i].push_back(root);
		for (int j = 0; j < num - 1; j++) {		
			cin >> member;
			members[i].push_back(member);
			graph[root].push_back(member);
			graph[member].push_back(root);
		}
	}

	cout << maxPartyNum() << "\n";

	return 0;
}

// 1차 시도 
int maxPartyNum0() {
	int ret = 0;
	UnionSet set;
	if (knowers.size() == 0) {
		return M;
	}
	int root = set.find(knowers[0]);
	for (int i = 1; i < knowers.size(); i++) {
		set.merge(root, knowers[i]);
	}
	for (int party = 0; party < M; party++) {
		for (int member : members[party]) {
			if (set.find(member) == root) {
				for (int m : members[party]) {
					set.merge(root, m);
				}
			}
		}
	}
	for (int party = 0; party < M; party++) {
		bool canLie = true;
		for (int member : members[party]) {
			if (set.find(member) == root) {
				canLie = false;
				break;
			}
		}
		if (canLie) {
			ret += 1;
		}
	}
	return ret;
}
