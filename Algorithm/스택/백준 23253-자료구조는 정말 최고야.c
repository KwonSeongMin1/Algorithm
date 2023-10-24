#include <stdio.h>
int book[200001];
int main() {
	int N, M, flag = 1;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &book[j]);
		}

		for (int j = 0; j < n-1; j++) {	// i < i+1ÀÌ¸é ½ºÅÃ ±¸Á¶»ó ¸ø ²¨³¿
			if (book[j] < book[j + 1]) {
				flag = 0;
				break;
			}
		}
	}
	if (flag) printf("Yes");
	else printf("No");
}