#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int a;
	scanf("%d", &a);
	int* pa = (int*)malloc(sizeof(int) * a);

	for (int i = 0; i < a; i++) {
		pa[i] = i;
		printf("%d : %d\n", i, pa[i]);
	}
	free(pa);
}