/*
https://www.acmicpc.net/problem/1753

ttps://www.acmicpc.net/problem/1753

23-06-12 20:40 ~ 21:10
1차 시도 : 틀림
- 테스트해볼 케이스
5 7
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
1 3 1

21:10 ~ 21:42
1차 수정 : 메모리 초과
- 2만 x 2만 크기의 배열이므로 메모리 제한을 초과함...
참고 : https://www.acmicpc.net/board/view/89296

23-06-13 12:40 ~ 13:00

14:30 ~ 15:30
2차 시도 : 틀림.
- 예전에 공부했던 지식이 잘못된 것 같음.
- 인접리스트와 우선순위 큐를 이용하는 NlogN 시간복잡도의 방법에 대해 알게 됨.
그동안 사용한 방법은 인접행렬을 이용한 N^2 시간복잡도의 방법임.
참고 : https://m.blog.naver.com/ndb796/221234424646

주의
- 그리고 INF 값에 주의해야 함. INF는 (정점 - 1) * 최대 가중치보다 커야 함!!!

16:19 ~ 16:57

- 그러나 여전히 시간 초과가 발생했음
- 질문 글에서 답을 찾음. 이 문제는 시간에 민감한 문제임.
일단 입력 데이터가 많으므로 빠른 입출력을 사용하는 것이 좋음.
그리고 우선순위 큐에서 정렬의 기준이 되는 것은 거리이므로 
거리가 짧은 것이 먼저 오도록 코딩하는 것이 필요함.

주의
- 우선순위 큐에서 거리가 짧은 것이 먼저 pop되도록 거리를 음수화해야함. 또는 비교함수 정의해야함.
- 큐에 pair<>로 저장 시 first에 거리를 저장해야 불필요한 계산이 줄어듬.

참고 : https://www.acmicpc.net/board/view/75599
, https://www.acmicpc.net/board/view/90770

*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 5000000 // 무한대 값이 (정점 - 1) * 최대 가중치 보다 커야함
using namespace std;

int V, E;
vector<pair<int, int>> graph[20001];
int path[20001];

void dijkstra(int start) {
	priority_queue <pair<int, int>> pq;
	for (int i = 1; i <= V; i++) {
		path[i] = INF;
	}
	path[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int dist = -pq.top().first; // 음수화에 주의, first에 거리를 저장해야 효율적으로 계산 가능
		int now = pq.top().second;
		pq.pop();
		if (path[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++) { // 원소를 순회하는 for문을 사용하는 것과 차이가 날까? 
			int next = graph[now][i].first;
			int nextDistance = dist + graph[now][i].second;
			if (nextDistance < path[next]) {
				path[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next)); 
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); // 입력 데이터의 크기가 클 경우 빠른 입출력을 사용하자.
	cin.tie(NULL);
	cout.tie(NULL);

	int K, u, v, w;
	cin >> V >> E;
	cin >> K;
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w)); // make_pair와 {}는 차이가 클까?
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (path[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << path[i] << "\n";
		}
	}

	return 0;
}

