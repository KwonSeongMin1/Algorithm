#include <stdio.h>

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return -1;
	else if (*(int*)first < *(int*)second)
		return 1;
	else
		return 0;
}

int main() {
	int c, max = 0, result;
	int doll[1001];
	scanf("%d", &c);
	result = c;
	for (int i = 0; i < c; i++) {
		scanf("%d", &doll[i]);
	}

	qsort(doll, c, sizeof(int), compare);

	for (int i = 0; i < c-1; i++) {
		max = doll[i];
		for (int j = i + 1; j < c; j++) {
			if (!doll[j]) continue;
			if (max > doll[j]) {
				result--;
				max = doll[j];
				doll[j] = 0;
			}
		}
	}

	printf("%d", result);
}