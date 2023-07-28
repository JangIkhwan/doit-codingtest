/*
https://www.acmicpc.net/problem/13251

23-07-27 12:26

�������� ����� ���� ����ؼ� Ȯ���� ���ϸ� �Ǵ� ������ ����

a1 C k + a2 C k + ... + am C k / n C k

ù �õ� ����
printf("%d\n", C[50][25]); // 10���� �����Ƿ�  sum �� 50�� �� �� ����

�ݷ�
10
50 50 50 50 50 50 50 50 50 50
25
5.79130368887

Ȯ���� �и� �ش��ϴ� ����� ���� �������� �Ի��ϸ� �����÷ο찡 �߻��� �� ����

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int C[51][51];

int main(void) {
	int M, K, N;
	int colorNum[51];
	long long sum; //
	double result;
	scanf("%d", &M);
	N = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d", &colorNum[i]);
		N += colorNum[i];
	}
	scanf("%d", &K);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 0 || i == j) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}
	sum = 0;
	for (int i = 1; i <= M; i++) {
		if (colorNum[i] >= K) {
			sum += C[colorNum[i]][K];

		}
	}
	double totalCase = 1.0;
	for (int i = K; i >= 1; i--) {
		totalCase = (double) (N - K + i) / i;
	}
	result = (double)sum / totalCase;
	printf("sum = %llf\n", totalCase);
	//printf("sum = %llf\n", (double)sum);
	printf("%.11lld", result);
	return 0;
}


int main1(void) {
	int M, K, N;
	int colorNum[51];
	long long sum; //
	double result;
	scanf("%d", &M); 
	N = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d", &colorNum[i]);
		N += colorNum[i];
	}
	scanf("%d", &K);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 0 || i == j) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}
	sum = 0;
	for (int i = 1; i <= M; i++) {
		if (colorNum[i] >= K) {
			sum += C[colorNum[i]][K];
			
		}
	}
	double totalCase = 1.0;
	for (int i = K; i >= 1; i--) { //
		totalCase *= (double)(N + K - i) / i;
	}
	printf("total = %llf\n", totalCase);
	result = (double)sum / totalCase;
	printf("%.11lf", result);
	return 0;
}

int main0(void) {
	int M, K, N;
	int colorNum[51];
	long long sum; //
	double result;
	scanf("%d", &M);
	N = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d", &colorNum[i]);
		N += colorNum[i];
	}
	scanf("%d", &K);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 0 || i == j) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}
	sum = 0;
	for (int i = 1; i <= M; i++) {
		if (colorNum[i] >= K) {
			sum += C[colorNum[i]][K];

		}
	}
	long long totalCase;
	long long above = 1.0;
	for (int i = N; i >= (N - K + 1); i--) {
		above *= i;
	}
	printf("above = %lld\n", sum);
	long long below = 1.0;
	for (int i = K; i >= 1; i--) { //
		below *= i;
	}
	printf("below = %lld\n", sum);
	totalCase = above / below;
	printf("total = %lld\n", totalCase);
	result = (double)sum / (double)totalCase;
	printf("%.11lf", result);
	return 0;
}
