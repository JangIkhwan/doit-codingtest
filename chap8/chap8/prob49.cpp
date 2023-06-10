/*
https://www.acmicpc.net/problem/2251

23-06-05 17:40 ~ 18:25
1차 시도 : 모르겠음

23-06-06 12:00 ~ 12:35
2차 시도 : 모르겠음

14:40 ~ 15:28
힌트 참고 : 물통들의 상태를 탐색하는 문제로 생각?
- 6진 트리를 탐색하는 형태일 것 같음...

생각해볼 점
- 사실 이렇게 directs 배열을 이용하는 것보다 a, b, c 사이에 주고 받는 것을 직접 작성하는 것이 더 쉬울 것 같음...
- 다음에는 시간을 단축할 수 있는 방향으로 작성해보자. 코드의 유연성을 고려하기보다는 더 빨리 정확하게 푸는 것이 중요!
- 문제에서 답이 가지는 특성을 파악했으면 더 좋았을 것 같음. a, b,c 에 담겨 있는 물의 총 합은 C의 총용량임. 
2개의 양만 알아도 나머지 양을 알 수 있으므로 메모리를 절약할 수 있음.
- 정답을 저장하는 과정에서 중복되는 값이 저장되지 않을까 싶었는데, 위의 특성 때문에 모든 답은 한번씩만 저장되니 신경쓸 필요 없음.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[201][201][201];
vector<int> liters;

int sizes[3];
int directs[6][2] = {
	{0, 1}, {0, 2},
	{1, 0}, {1, 2},
	{2, 0}, {2, 1}
};

void findRemainLiters() {
	queue<pair<int, pair<int, int>>> qu;
	int amounts[3];
	int newAmounts[3];
	visited[0][0][sizes[2]] = true;
	liters.push_back(sizes[2]);
	qu.push(make_pair(0, make_pair(0, sizes[2]))); // 오타에 주의
	while (!qu.empty()) {
		auto front = qu.front();
		qu.pop();
		amounts[0] = front.first;
		amounts[1] = front.second.first;
		amounts[2] = front.second.second;
		for (int i = 0; i < 6; i++) {  // 6진트리 탐색 코드. 너무 어렵게 생각한 것 같기도 함.
			int src = directs[i][0];
			int dst = directs[i][1];
			for (int j = 0; j < 3; j++) {
				newAmounts[j] = amounts[j];
			}
			if (amounts[src] != 0) {
				if (sizes[dst] - amounts[dst] >= amounts[src]) {
					newAmounts[src] = 0;
					newAmounts[dst] += amounts[src];
				}
				else {
					newAmounts[src] -= sizes[dst] - amounts[dst];
					newAmounts[dst] = sizes[dst];
				}
				bool &visit = visited[newAmounts[0]][newAmounts[1]][newAmounts[2]];
				if (!visit) {
					visit = true;
					if (newAmounts[0] == 0) {
						liters.push_back(newAmounts[2]);
					}
					qu.push(make_pair(newAmounts[0], make_pair(newAmounts[1], newAmounts[2])));
				}
			}
		}
	}
}

int main(void) {
	cin >> sizes[0] >> sizes[1] >> sizes[2];

	findRemainLiters();

	sort(liters.begin(), liters.end());

	int prev = -1;
	for (int i = 0; i < liters.size(); i++) {
		int now = liters[i];
		//if (prev != now) {
			cout << now << " ";
			prev = now;
		//}
	}

	return 0;
}