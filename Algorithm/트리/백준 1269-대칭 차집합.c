#include <stdio.h>

int A[200001];
int B[200001];
int compare(const void* x, const void* y)
{
	if (*(int*)x > *(int*)y)
		return 1;
	else if (*(int*)x < *(int*)y)
		return -1;
	else
		return 0;
}

int main() {
	int a, b, c = 0;
	scanf("%d %d", &a, &b);

	for (int i = 0; i < a; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < b; i++) {
		scanf("%d", &B[i]);
	}

	qsort(A, a, sizeof(int), compare);
	qsort(B, b, sizeof(int), compare);

	int x = 0;
	int y = 0;

	while (x != a && y != b) {
		if (A[x] < B[y]) {
			x++;
		}
		else if (A[x] > B[y]) {
			y++;
		}
		else {
			x++;
			y++;
			c++;
		}
	}
	printf("%d", (a + b) - (c * 2));
}