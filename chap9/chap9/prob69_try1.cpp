/*
23-06-25 21:53 ~ 
*/
#include <iostream>
using namespace std;

class Trie {
	bool isFinal;
	Trie* children[26];
public:
	Trie() {
		isFinal = false;
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}
	void insert(string& str, int index) {
		int cur = str[index] - 'a';
		if (children[cur] == NULL) {
			children[cur] = new Trie();
		}
		if (index == str.size() - 1) {
			children[cur]->isFinal = true;
			return;
		}
		children[cur]->insert(str, index + 1);
	}
	bool find(string& str, int index) {
		cout << index + 'a' << " ";
		if (children[index] != NULL) {	
			if (index >= str.size() - 1) {
				if (isFinal) {
					cout << "->final\n";
					return true;
				}
				else {
					cout << "->NO final\n";
					return false;
				}
			}
			return find(str, index + 1);
		}
		else {
			return false;
		}
	}
};

int main(void) {
	int N, M;
	Trie trie;
	string str;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		trie.insert(str, 0);
	}
	int matchCount = 0;
	for (int i = 1; i <= M; i++) {
		cin >> str;

		if (trie.find(str, 0)) {
			matchCount += 1;
		}
	}
	cout << matchCount << "\n";
	return 0;
}