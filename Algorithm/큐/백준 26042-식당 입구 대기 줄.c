#include <stdio.h>

int line[100001];
int main() {
	int n;
	int min = 100001, max = 0;	// ��� �����
	int k = 0, l = 0;	// ��� ����
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d", &x);

		// 1�϶� �Է¹ް� ����
		if (x == 1) {
			scanf("%d", &y);
			line[k++] = y;
		}

		// 2�϶� �� �� �� ����
		else {
			line[l++] = 0;
		}

		// k = �Է¹��� �� ����, l = ������ �� ����
		if (max < k - l) {
			max = k - l;
			min = line[k - 1];
		}
		else if (max == k - l) {
			if (min > line[k - 1]) min = line[k - 1];
		}
	}

	printf("%d %d", max, min);
}