/*
23-06-19 17:44 ~ 18:11

����ϱ�
- �÷��̵� �ͼ��� �߰������� ���ļ� ���� ��ΰ� �� ������ ��θ� ������
- �ð����⵵�� N^3��
- ��� ������ ���ؼ� �ٸ� �������� ���� �ִܰ�θ� ���� �� �̿���
- �� ����� ���� �����÷ο�� ���ؼ� ������ ���� �ʵ��� INF���� �� �����ؾ� ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
using namespace std;

int INF = 20000000; // INT_MAX�� �ȵ�. 
int N, M;
int W[101][101];
int result[101][101];

void floydWarshall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j && W[i][j] == 0) {
				result[i][j] = INF;
			}
			else{
				result[i][j] = W[i][j];
			}
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (result[i][k] + result[k][j] < result[i][j]) { //  INF ���� INF_MAX�� INF�� ���� ������ �Ǿ �ȵ�...
					result[i][j] = result[i][k] + result[k][j];
				}
			}
		}
	}
}

int main(void) {
	int a, b, c;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (W[a][b] == 0 || (W[a][b] != 0 && c < W[a][b])) {
			W[a][b] = c;
		}
	}

	floydWarshall(); //  �Լ�ȣ���� ���� ����...

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (result[i][j] == INF) {
				printf("0 ");
			}
			else {
				printf("%d ", result[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
