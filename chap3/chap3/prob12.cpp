/*
* 40분 경과로 실패..
* 재시도 16분 소요
* 
* 풀이 과정
* - 절댓값만 비교하면 상관이 없는데, 같은 값이 여러 개일 경우 음수를 먼저 출력해야 해서 문제였음
* - 양수와 음수를 같은 곳에 저장해서는 안됨
* - 절댓값이 작은 것부터 반환해야 하니 정렬이 필요함. 근데 정렬을 이용하면 시간 초과가 발생함
* - 생각해보니 우선순위 큐라는 자료구조가 있었음
* - 우선순위 큐 두 개에 양수와 음수를 구분해서 저장하고, 출력할 때 두 절댓값이 같으면 음수를 먼저 출력하면 됨.
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> posQu;
	priority_queue<int, vector<int>, greater<int>> negQu;
	queue<int> result;
	while (N-- > 0) {
		int oper;
		cin >> oper;
		if (oper == 0) {
			if (!posQu.empty() && !negQu.empty()) {
				if (negQu.top() <= posQu.top()) {
					result.push(-negQu.top());
					negQu.pop();
				}
				else {
					result.push(posQu.top());
					posQu.pop();
				}
				continue; // 윗 줄에 있던 것 내림
			}
			if (!posQu.empty()) {
				result.push(posQu.top());
				posQu.pop();
				continue;
			}
			if (!negQu.empty()) {
				result.push(-negQu.top());
				negQu.pop();
				continue;
			}
			result.push(0);
		}
		else if (oper > 0) {
			posQu.push(oper);
		}
		else {
			negQu.push(-oper);
		}
	}
	
	while (!result.empty()) {
		cout << result.front() << "\n";
		result.pop();
	}

	return 0;
}