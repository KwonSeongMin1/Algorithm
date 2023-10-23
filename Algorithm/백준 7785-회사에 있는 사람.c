#include <stdio.h>
#include <string.h>


int compare(const void* a, const void* b)
{
	return strcmp(b, a);
}

int main() {
	int N;
	char name[100001][6];
	char inout[6];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s", name[i], inout);
	}

	// Quick sort O(n logn)
	qsort(name, N, sizeof(name[0]), compare);


	// Bubble sort O(n^2)
	/*for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (strcmp(name[i], name[j]) == -1) {
				char temp[6];
				strcpy(temp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp);
			}
		}
	}*/

	for (int i = 0; i < N; i++) {
		if (strcmp(name[i], name[i+1]) == 0) {
			i++;
		}
		else {
			printf("%s\n", name[i]);
		}
	}
}