#include <stdio.h>

int main() {
	int n, k, i = 0, c = 1, vanishedNumCount = 0;
	scanf("%d %d", &n, &k);

	int list[5001];

	for (int i = 0; i < n; i++) {
		list[i] = i + 1;
	}

	printf("<");
	while (vanishedNumCount != n) {
		if (list[i] == 0) {
			i = (i + 1) % n;
			continue;
		}
		if (c == k) {
			printf("%d", list[i]);
			list[i] = 0;
			c = 0;
			vanishedNumCount++;
			if (vanishedNumCount != n) {
				printf(", ");
			}
		}
		c++;
		i = (i + 1) % n;
	}
	printf(">");
}
