#include <stdio.h>

int main() {
	int card[1002] = { 0 };
	int n,c = 2;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		card[i] = i + 1;
	}

	while (card[0] != 0) {
		printf("%d ", card[0]);
		card[0] = 0;
		card[n] = card[1];
		card[1] = 0;

		for (int i = 2; i <= n; i++) {
			card[i - 2] = card[i];
		}
		n--;
	}
}