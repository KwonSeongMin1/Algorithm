#include <stdio.h>

int main() {
	int n,c,x,y;
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		x = 0, y = 0;
		char chr[26][26] = { 0 };
		while ((c = getchar()) != '\n') {
			if (c != ' ') {
				chr[x][y] = c;
				y++;
			}
			else {
				y = 0;
				x++;
			}
		}
		
		printf("Case #%d: ", i + 1);
		for (int i = x; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				if(chr[i][j]) printf("%c", chr[i][j]);
			}
			printf(" ");
		}
		printf("\n");
	}
}