#include <stdio.h>
int n[1000001];
int m[1000001];
int main() {
	int N, M, count;
	while (1) {
		count = 0;
		scanf("%d %d", &N, &M);
		if (!N && !M) break;
		for (int i = 0; i < 1000001; i++) {
			n[i] = 0;
			m[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &n[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &m[i]);
		}

		int i = 0;
		int j = 0;

		while (i != N && j != M) {
			if (n[i] == m[j]) {
				count++;
				i++;
				j++;
			}
			else if (n[i] > m[j] && j != M - 1) {
				j++;
			}
			else if (n[i] < m[j] && i != N - 1) {
				i++;
			}
			else break;
		}
		printf("%d\n", count);
	}
}