/*
����:
https://www.acmicpc.net/board/view/50494

����ϱ�
- ��������� �� �������� �ٸ� ����������� �ִ� �Ÿ��� ���� �� ����� �� ����.
�̶� INF ���� ���� ���� ���θ� �Ǵ��ϱ� ���ؼ� �����
- �׷��� ����Ŭ�� �ִ��� ���θ� �Ǵ��� ��, �ִܰŸ��� ���ϴ� �ڵ带 �״�� ����ϸ�
����Ŭ�� ������� �ʴ� ������ ������ �� ����. �׷��� �Ǹ� ����Ŭ�� Ž������ ����.
- �׷��� ����Ŭ�� �ִ��� ���θ� �Ǵ��� ���� dist���� INF���� �Ǵ��� �ʿ䰡 ����.
- ��� ��带 ���������� �Ͽ��� �������带 �����ϴ� ����� ������ �ð��ʰ��� �߻��� �� ����.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
	int start, end, weight;
};

int TC, N, M, W;

int dist[501];
vector<Edge> edgeList;

bool bellmanFord() {
	bool hasCycle = false;
	for (int i = 1; i <= N; i++) {
		dist[i] = 0;
	}
	for (int i = 1; i <= N; i++) { //
		for (const Edge& edge : edgeList) {
			int s = edge.start;
			int e = edge.end;
			int w = edge.weight;
			if (dist[s] + w < dist[e]) {
				dist[e] = dist[s] + w;
				if (i >= N) {
					hasCycle = true;
				}
			}
		}
	}
	return hasCycle;
}

int main(void) {
	int s, e, t;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d %d", &N, &M, &W);
		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d", &s, &e, &t);
			edgeList.push_back({ s, e, t });
			edgeList.push_back({ e, s, t });
		}
		for (int i = 1; i <= W; i++) {
			scanf("%d %d %d", &s, &e, &t);
			edgeList.push_back({ s, e, -t }); //
		}
		bool hasCycle = bellmanFord();
		if (hasCycle) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		edgeList.clear();
	}
	return 0;
}
