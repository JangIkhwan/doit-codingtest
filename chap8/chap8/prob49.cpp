/*
https://www.acmicpc.net/problem/2251

23-06-05 17:40 ~ 18:25
1�� �õ� : �𸣰���

23-06-06 12:00 ~ 12:35
2�� �õ� : �𸣰���

14:40 ~ 15:28
��Ʈ ���� : ������� ���¸� Ž���ϴ� ������ ����?
- 6�� Ʈ���� Ž���ϴ� ������ �� ����...

�����غ� ��
- ��� �̷��� directs �迭�� �̿��ϴ� �ͺ��� a, b, c ���̿� �ְ� �޴� ���� ���� �ۼ��ϴ� ���� �� ���� �� ����...
- �������� �ð��� ������ �� �ִ� �������� �ۼ��غ���. �ڵ��� �������� ����ϱ⺸�ٴ� �� ���� ��Ȯ�ϰ� Ǫ�� ���� �߿�!
- �������� ���� ������ Ư���� �ľ������� �� ������ �� ����. a, b,c �� ��� �ִ� ���� �� ���� C�� �ѿ뷮��. 
2���� �縸 �˾Ƶ� ������ ���� �� �� �����Ƿ� �޸𸮸� ������ �� ����.
- ������ �����ϴ� �������� �ߺ��Ǵ� ���� ������� ������ �;��µ�, ���� Ư�� ������ ��� ���� �ѹ����� ����Ǵ� �Ű澵 �ʿ� ����.
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
	qu.push(make_pair(0, make_pair(0, sizes[2]))); // ��Ÿ�� ����
	while (!qu.empty()) {
		auto front = qu.front();
		qu.pop();
		amounts[0] = front.first;
		amounts[1] = front.second.first;
		amounts[2] = front.second.second;
		for (int i = 0; i < 6; i++) {  // 6��Ʈ�� Ž�� �ڵ�. �ʹ� ��ư� ������ �� ���⵵ ��.
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