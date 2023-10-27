#include <stdio.h>

char skill[200001];
char lr[200001];
char sk[200001];


int main() {
	int n, x = 0, y = 0, count = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf(" %c", &skill[i]);
		if (skill[i] == 'L') {
			lr[x++] = skill[i];
		}
		else if (skill[i] == 'S') {
			sk[y++] = skill[i];
		}
		else if (skill[i] == 'R' || skill[i] == 'K') {
			if (lr[x - 1] == 'L' && skill[i] == 'R') {
				lr[x - 1] = 0;
				x--;
				count++;
			}
			else if (sk[y - 1] == 'S' && skill[i] == 'K') {
				sk[y - 1] = 0;
				y--;
				count++;
			}
			else break;
		}
		else count++;
	}

	printf("%d", count);

}