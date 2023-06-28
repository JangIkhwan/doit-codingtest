/*
https://www.acmicpc.net/problem/1991

23-06-27 21:15 ~ 21:43
1차 시도 실패

21:43 ~ 22:

기억할 부분
- 부모 노드를 식별할 수 있는 정보가 있다면 부모를 저장해두었다가 식별 정보로 다시 찾을 수 있음 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
	TreeNode* left, *right;
	char alpha;
	TreeNode(char ch) {
		left = right = NULL;
		alpha = ch;
	}
};

void preorder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c", root->alpha);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%c", root->alpha);
	inorder(root->right);
}

void postorder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->alpha);
}

int main(void) {
	int N;
	TreeNode* nodes[26];
	char root, left, right;
	scanf("%d", &N);
	nodes[0] = new TreeNode('A');
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c %c %c", &root, &left, &right);
		if (left != '.') {
			nodes[root - 'A']->left = nodes[left - 'A'] = new TreeNode(left);
		}
		if (right != '.') {
			nodes[root - 'A']->right = nodes[right - 'A'] = new TreeNode(right);
		}
	}

	preorder(nodes[0]);
	printf("\n");
	inorder(nodes[0]);
	printf("\n");
	postorder(nodes[0]);
	printf("\n");

	return 0;
}