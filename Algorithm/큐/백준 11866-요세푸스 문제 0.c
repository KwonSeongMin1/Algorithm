#include <stdio.h>

int main() {
	int queue[1001];
	int n, k, i = 0, c = 0, count = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		queue[i] = i + 1;
	}
	printf("<");

	while (count!=n-1) {

		if (queue[i] == 0) {	// if 0 continue
			i++;
			if (i == n) i = 0;	// continue�Ҷ� ������ �� ó������
			continue;
		}
		c++;	// K��° ī��Ʈ
		if (c == k) {	// K��°�϶�
			printf("%d, ",queue[i]);
			queue[i] = 0;
			count++;
			c = 0;
		}
		if (i == n-1) {
			i = 0;	// �� ó������
			continue;
		}
		i++;
	}

	for (int i = 0; i < n; i++) {
		if (queue[i]) printf("%d>", queue[i]);
	}
}