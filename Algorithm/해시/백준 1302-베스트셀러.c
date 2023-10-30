#include <stdio.h>
#include <string.h>

typedef struct {
	int sellCount;
	char name[51];
}Book;

int compare1(const void *x, const void *y) {
	return strcmp(x, y);
}

int compare2(const void* x, const void* y) {
	Book* xx = (Book*)x;
	Book* yy = (Book*)y;

	if (xx->sellCount < yy->sellCount) return 1;
	if (xx->sellCount > yy->sellCount) return -1;
	return strcmp(xx->name, yy->name);
}

int main() {
	int n, x = -1;
	scanf("%d", &n);
	
	char book[1001][51];
	Book sellBook[1001];

	for (int i = 0; i < n; i++) {
		scanf("%s", book[i]);
	}

	char cmp[51] = "";
	
	qsort(book, n, sizeof(book[0]), compare1);

	for (int i = 0; i < n; i++) {
		if (!strcmp(book[i], cmp)) {
			sellBook[x].sellCount++;
		}
		else {
			x++;
			strcpy(cmp, book[i]);
			strcpy(sellBook[x].name, book[i]);
			sellBook[x].sellCount = 1;
		}
	}

	qsort(sellBook, x + 1, sizeof(sellBook[0]), compare2);

	/*for (int i = 0; i < x+1; i++) {
		printf("%s %d\n", sellBook[i].name, sellBook[i].sellCount);
	}*/

	printf("%s", sellBook[0].name);

}