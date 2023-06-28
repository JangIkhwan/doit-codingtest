/*
https://www.acmicpc.net/problem/14425

23-06-26 16:53 ~ 17:21  

생각할 점
- 나는 트라이를 이용해서 풀었지만 map을 이용할 수도 있는 것 같음. 
나중에 map을 이용한 방법을 공부해보자.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int CHARMAX = 26;
int toNumber(char ch) { return ch - 'a'; }

class TrieNode {
public:
	bool isTerminal;
	TrieNode* children[CHARMAX];
	TrieNode() {
		isTerminal = false;
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < CHARMAX; i++) {
			if (children[i] != NULL) delete children[i];
		}
	}
	void insert(char* ch) {
		if (*ch == NULL) {
			isTerminal = true;
			return;
		}
		int next = toNumber(*ch);
		if (children[next] == NULL) {
			children[next] = new TrieNode;
		}
		children[next]->insert(ch + 1);
	}
	TrieNode* find(char* ch) {
		if (*ch == NULL) {
			return this;
		}
		int next = toNumber(*ch);
		if (children[next] == NULL) {
			return NULL;
		}
		return children[next]->find(ch + 1);
	}
};

int main(void) {
	int N, M;
	char input[600];
	TrieNode trie;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", input);
		trie.insert(input);
		memset(input, 0, sizeof(input));
	}
	int inCount = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%s", input);
		TrieNode* ret = trie.find(input);
		if (ret != NULL && ret->isTerminal) {
			inCount += 1;
		}
		memset(input, 0, sizeof(input));
	}
	
	printf("%d\n", inCount);

	return 0;
}