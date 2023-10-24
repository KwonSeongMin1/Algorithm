#include <stdio.h>

// 순차 자료구조로 풀이
int main() {
	int student;
	int l;
	int line[101] = { 0 };

	scanf("%d", &student);

	for (int i = 0; i < student; i++) {
		scanf("%d", &l);
		if (l == 0) line[i] = i + 1;
		else {
			for (int j = i; j > i-l; j--) {
				line[j] = line[j - 1];
			}
			line[i - l] = i + 1;
		}
	}

	for (int i = 0; i < 101; i++) {
		if (line[i] == 0) break;
		printf("%d ", line[i]);
	}
}