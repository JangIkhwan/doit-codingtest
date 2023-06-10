/*
23-06-10 16:02 ~ 16:43
2차시도 : 틀렸음


*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//int memo[501];
int buildTime[501];
vector<int> subBuildings[501];
bool builded[501];

int getTotalTime(int cur) {
	int ret = buildTime[cur];
	builded[cur] = true;
	for (int sub : subBuildings[cur]) {
		if (!builded[sub]) {
			ret += getTotalTime(sub);
		}
	}
	return ret;
}


int main(void) {
	int N, subBuilding;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> buildTime[i];
		while (true) {
			cin >> subBuilding;
			if (subBuilding == -1) {
				break;
			}
			subBuildings[i].push_back(subBuilding);
		}
	}
	//memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= N; i++){
		memset(builded, 0, sizeof(builded));
		cout << getTotalTime(i) << "\n";
	}
	return 0;
}
