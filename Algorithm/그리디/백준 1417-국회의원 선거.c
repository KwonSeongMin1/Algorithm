#include <stdio.h>

int main() {
	int n, target, MAX, count = 0;
	int K[50];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &K[i]);
	}

	while (1) {
		target = 0;
		MAX = 0;
		for (int i = 0; i < n; i++) {
			if (K[i] >= MAX) {
				MAX = K[i];
				target = i;
			}
		}

		if (K[0] == MAX && target == 0) break;

		if (K[0] <= MAX) {
			K[0]++;
			K[target]--;
			count++;
		}
	}

	printf("%d", count);

}