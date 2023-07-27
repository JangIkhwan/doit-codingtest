/*
23-07-24 20:11 ~ 9:06
- w�� �ܾ�� Ʈ���� ����
- ���ڿ��� ���λ簡 Ʈ���̿� �����ϴ��� Ȯ��
- ���λ簡 Ʈ���̿� ������ �� ���ڸ� ���� ���ڿ��� ��� Ȯ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX = 26;

int getIndex(char ch) {
	return ch - 'a';
}

typedef struct TrieNode {
	TrieNode* children[MAX];
	bool isEnd;
	TrieNode() {
		for (int i = 0; i < MAX; i++) {
			children[i] = NULL;
		}
		isEnd = false;
	}
	~TrieNode() {
		for (int i = 0; i < MAX; i++) {
			if (children[i] != NULL) {
				delete children[i];
			}
		}
	}
	void insert(char *ch) {
		if (*ch == NULL) {
			isEnd = true;
			return;
		}
		int index = getIndex(*ch);
		if (children[index] == NULL) {
			children[index] = new TrieNode;
		}
		children[index]->insert(ch + 1);
	}
	bool find(char* ch) {
		if (*ch == NULL) {
			if (isEnd) {
				return true;
			}
			return false;
		}
		int index = getIndex(*ch);
		if (children[index] == NULL) {
			return false;
		}
		children[index]->find(ch + 1);
	}
}TrieNode;



int main(void) {
	int w, l;
	char S[301];
	char word[26];
	TrieNode trie;
	scanf("%d %d", &w, &l);
	scanf("%s", S);
	for (int i = 1; i <= w; i++) {
		scanf("%s", word);
		trie.insert(word);
	}
	
	return 0;
}