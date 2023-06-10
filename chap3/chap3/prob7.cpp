/*
23-05-09
*/

#include <iostream>
#include <string>
using namespace std;

int aLowBound, cLowBound, gLowBound, tLowBound;
int aNum = 0, cNum = 0, gNum = 0, tNum = 0;

void insert(char inserted) {
	if (inserted == 'A') {
		aNum += 1;
	}
	else if (inserted == 'C') {
		cNum += 1;
	}
	else if (inserted == 'G') {
		gNum += 1;
	}
	else {
		tNum += 1;
	}
}

void remove(char removed) {
	if (removed == 'A') {
		aNum -= 1;
	}
	else if (removed == 'C') {
		cNum -= 1;
	}
	else if (removed == 'G') {
		gNum -= 1;
	}
	else {
		tNum -= 1;
	}
}

int main(void) {
	int dnaLen, PatternLen;
	
	string dna;
	cin >> dnaLen >> PatternLen;
	cin >> dna;
	cin >> aLowBound >> cLowBound >> gLowBound >> tLowBound;

	int passwordCount = 0;
	for (int s = 0; s < PatternLen; s++) {
		insert(dna[s]);
	}
	if (aNum >= aLowBound && cNum >= cLowBound && gNum >= gLowBound && tNum >= tLowBound) {
		passwordCount += 1;
	}

	int start = 0;
	int end = PatternLen - 1;
	while (end < dnaLen - 1){ // 윈도우를 이동시키려면 end가 dna 문자열의 끝에 있어서는 안됨
		remove(dna[start]);
		insert(dna[end + 1]);
		start += 1;
		end += 1;
		if (aNum >= aLowBound && cNum >= cLowBound && gNum >= gLowBound && tNum >= tLowBound) {
			passwordCount += 1;
		}
	}

	cout << passwordCount << "\n";
}