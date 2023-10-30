#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int num;
	char name[21];
}Pocketmon;

int compare(const void* x, const void* y) {
	Pocketmon* xx = (Pocketmon*) x;
	Pocketmon* yy = (Pocketmon*) y;

	return strcmp(xx->name, yy->name);
}

Pocketmon p[100001];
Pocketmon pCopy[100001];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", p[i].name);
		strcpy(pCopy[i].name, p[i].name);
		p[i].num = i + 1;
		pCopy[i].num = i + 1;
	}

	qsort(pCopy, n, sizeof(Pocketmon), compare);

	for (int i = 0; i < q; i++) {
		char question[21];
		scanf("%s", question);
		if (question[0] >= 48 && question[0] <= 57) {
			int x = atoi(question);
			printf("%s\n", p[x-1].name);
		}
		else {
			int start = 0;
			int end = n - 1;
			int mid;
			while (start <= end) {
				mid = (start + end) / 2;
				int j = strcmp(pCopy[mid].name, question);
				if (j==0) {
					break;
				}
				else if (j>0) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			printf("%d\n", pCopy[mid].num);
		}
	}

}