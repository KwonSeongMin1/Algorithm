#include <stdio.h>
#include <string.h>

char cantHear[500001][21];
char cantSee[500001][21];
char cantHearSee[500001][21];

int compare(const void* x, const void* y) {

	return strcmp(x, y);
}
int main() {
	int n, m, count = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", &cantHear[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%s", &cantSee[i]);
	}

	qsort(cantHear, n, sizeof(cantHear[0]), compare);
	qsort(cantSee, m, sizeof(cantSee[0]), compare);

	int x = 0;
	int y = 0;

	while (x != n && y != m) {
		if (!strcmp(cantHear[x], cantSee[y])) {
			strcpy(cantHearSee[count++], cantHear[x]);
			x++;
			y++;
		}
		else if (strcmp(cantHear[x], cantSee[y]) < 0) x++;
		else y++;
	}

	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%s\n", cantHearSee[i]);
	}
}