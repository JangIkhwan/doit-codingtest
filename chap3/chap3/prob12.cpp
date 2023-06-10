/*
* 40�� ����� ����..
* ��õ� 16�� �ҿ�
* 
* Ǯ�� ����
* - ���񰪸� ���ϸ� ����� ���µ�, ���� ���� ���� ���� ��� ������ ���� ����ؾ� �ؼ� ��������
* - ����� ������ ���� ���� �����ؼ��� �ȵ�
* - ������ ���� �ͺ��� ��ȯ�ؾ� �ϴ� ������ �ʿ���. �ٵ� ������ �̿��ϸ� �ð� �ʰ��� �߻���
* - �����غ��� �켱���� ť��� �ڷᱸ���� �־���
* - �켱���� ť �� ���� ����� ������ �����ؼ� �����ϰ�, ����� �� �� ������ ������ ������ ���� ����ϸ� ��.
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
				continue; // �� �ٿ� �ִ� �� ����
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