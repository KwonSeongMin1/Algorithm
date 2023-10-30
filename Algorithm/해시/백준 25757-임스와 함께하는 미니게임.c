#include <stdio.h>
#include <string.h>
char player[100001][21];

int compare(const void* a, const void* b)
{
	return strcmp(b, a);
}

int main() {
	int n, user, result = 0,x = 0, count=0;
	char game;
	char p[21];

	scanf("%d %c", &n, &game);

	switch (game) {
	case 'Y':
		user = 1;
		break;
	case 'F':
		user = 2;
		break;
	case 'O':
		user = 3;
		break;
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", player[i]);
	}

	qsort(player, n, sizeof(player[0]), compare);

	strcpy(p, player[0]);

	for (int i = 1; i < n; i++) {
		if (!strcmp(p, player[i])) {
			strcpy(player[i], "");
		}
		else {
			strcpy(p, player[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (strcmp(player[i],"")) count++;
		if (count == user) {
			result++;
			count = 0;
		}

	}

	printf("%d", result);
}